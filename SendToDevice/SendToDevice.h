#ifndef SENDTODEVICE_H
#define SENDTODEVICE_H

/**
 *  Licença de uso.
 *
 *  Este código/repositório tem a finalidade de ajudar programadores de hardware a entenderem melhor programação C++ para
 *  as necessidades de hardware, possibilitando a criação de códigos C++ livres de plataforma, onde o mesmo código deve
 *  rodar em uma placa Arduino simples e também em um Linux ( x86, x64, ARM ), Mac Os X e [Ru]Windows.
 *
 *  Todos os códigos são distribuídos com o intuito de ajudar, porém, são distribuídos sem garantia de funcionamento
 *  ou obrigação de suporte de qualquer tipo de minha parte.
 *
 *  Você é livre para copiar, modificar e distribuir meu código livremente, porém, sempre que fizer algum tipo de
 *  alteração deve deixar claro o fato de não ser o meu código original e sempre que usar meu código, tem a obrigação de
 *  mencionar meu nome como desenvolvedor original.
 *
 *  Ass.: Helmut Kemper - helmut.kemper@gmail.com
 */

#include "../typesKemper.h"

// Não altere estas constantes
// Do not change these constants
#define SEND_TO_DEVICE_FLAG_RUNING 0
#define SEND_TO_DEVICE_FLAG_NEXT_STEP 1
#define SEND_TO_DEVICE_FLAG_WAITING 2
#define SEND_TO_DEVICE_FLAG_CHECK_END 3
#define SEND_TO_DEVICE_FLAG_PROCCESS_END 4
#define SEND_TO_DEVICE_FLAG_EVENT_SEND 5
#define SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND 6

/**
 *  @brief Esta classe tem a finalidade de fazer a troca de dados entre um hardware serial e um dispositivo AT, Modem e
 *         ODB-II, mas, também foi testada para se montar uma mini estrutura de servidor web montada em uma placa
 *         FRDM-K64F da Freescale ( http://www.freescale.com ) e testada no portal MBed ( http://www.mbed.org ).
 *
 *         Basicamente esta classe é uma máquina de estados feita para passar informações e esperar pela resposta do
 *         dispositivo, caso necessário.
 *
 *         Para isto, imagine um modem baseado em protocolo AT, como o SIM900, muito comum em projetos Arduino. O
 *         protocolo consiste em passar mensagens de texto simples entre o hardware e o modem, de forma a gerar tarefas
 *         simples, como acessar internet ou passar e receber SMS.
 *
 *         No caso do envio de SMS pelo modem SIM900, o protocolo seria:
 *
 *         Enviar:  "AT+CMGF=1\r\n"
 *         Receber: "OK\r\n"
 *         Enviar:  "AT+CMGS="número do telefone"\r\n"
 *         Receber: "> "
 *         Enviar:  "mensagem de texto"
 *         Enviar:  "char( 0x1A )"
 *         Receber: "OK\r\n"
 *
 *         Como dá para ver, existem uma série de pequenos passos a serem cumpridos, todos de forma síncrona, onde o
 *         próximo dado a ser transmitido necessita esperar para resposta de conclusão do passo anterior.
 *
 *         Antes de usar esta classe, tenha em mente que a mesma foi testada em Arduino Mega e deve rodar independente
 *         da plataforma, e o template foi pensado para dados tipo char ou unsigned char, não tendo sido testado para
 *         string ou dados mais complexos.
 *
 *         A classe também prevê a necessidade de se preparar um array de char antes do envio, onde uma constate pode
 *         perfeitamente ser montada de acordo com a necessidade da operação, apontando para o array de char contendo
 *         os dados a serem enviados sem maiores problemas.
 *
 *         Esta classe tem os seguintes templates:
 *         template class SendToDevice<const char, char, unsigned char, unsigned char>;
 *         template class SendToDevice<const unsigned char, unsigned char, unsigned char, unsigned char>;
 *
 *         Para o recebimento dos dados, esta classe recebe dados unitários, um char por vez, e usa ponteiros externos
 *         para varrer um modelo de string esperada e procurar por dados contidos dentro da string e arquivar os dados em
 *         variáveis esternas.
 *
 *         No envio de dados, existem duas possibilidades, uma função chamada a cada char a ser enviado, ou um buffer de
 *         char, onde uma função externa é chamada sempre que buffer estiver pronto ou lotado.
 *
 *         Boa Sorte.
 *         Kemper
 *
 *  @tparam class typeDataToExchange, é o tipo de dado a ser transmitido ao dispositivo externo. Geralmente const char*
 *          ou const unsigned char*.
 *
 *  @tparam class typeDataToMountBeforeExchange, é o tipo de dado a ser concatenado junto as constantes a serem enviadas
 *          aos dispositivo. Se a constante é do tipo const unsigned char*, o dado deve ser unsigned char* e se a
 *          constante for const char*, o dado deve ser char*.
 *
 *  @tparam class typeStackStepsSize, este é o tipo de dado da variável que indica o espaço de memória necessário para a
 *          quantidade de passos máximos necessários. Por exemplo, o envio de SMS pelo modem necessita de três passos
 *          distintos, por isto, unsigned char é mais do que suficiente para a tarefa.
 *
 *  @tparam class typeStackDataSize, este é o tipo de dado da variável que indica o espaço de memória necessário para a
 *          quantidade de dados máximos a serem concatenados nas constantes referentes a tarefa. Por exemplo, o envio de
 *          SMS pelo modem necessita de duas variáveis distintas, o telefone e o texto de envio, por isto, unsigned char
 *          é mais do que suficiente para a tarefa.
 */
template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
class SendToDevice
{
  public:
    /**
     * @brief SendToDevice, construtor da classe, responsável por alocar dinamicamente o espaço de memória da fila de
     *        constantes e da fila de variáveis usadas na hora de montar as constantes. Defina o valor máximo de cada
     *        fila com o cuidado de alocar apenas a quantidade de espaço necessário para a tarefa e nada a mais.
     *
     * @param stackStepsSizeAUCh, quantidade máxima ( +1 ) de registros na fila de constantes a serem enviadas ao
     *        dispositivo.
     *        Perceba que a classe foi feita de modo a cada constante a ser enviada ter no máximo uma constante a ser
     *        recebida, por isto, a alocação de espaço será sempre o dobro da determinada.
     *
     * @param stackDataSizeAUCh, quantidade máxima ( +1 ) de registros na fila de variáveis a serem concatenadas com a
     *        lista de constantes. A quantidade máxima de registros na memória depende da forma como as constantes
     *        foram criadas e da quantidade de constantes usadas por processo. Veja uma explicação mais detalhada abaixo.
     *
     * @code
                // Você necessita enviar um comando ao modem para pegar a hora do RTC, então, em algum lugar do código
                // tem a constante global abaixo
                const char MODEM_SEND_COMMAND_GET_RTC[] = { "AT+CCLK?\r\n\0" };
                // Segundo o manual do modem, a resposta do modem será: "+CCLK: \"09/10/15,19:33:42+00\"\r\n"
                // Para capturar a data e a hora, você deve montar a seguinte constante em algum lugar do código:
                const char MODEM_RECEIVE_RTC[] = { "+CCLK: \"{time},{time}{snum}\0" };
                // A classe vai comparar, sem capturar, os dados recebidos até encontrar os modificadores de
                // captura abaixo.
                // {time} - Captura data/hora no formato: [0-9]{1,}[:/][0-9]{1,}[:/][0-9]{1,}
                // {snum} - Captura número, formato: [0-9+-]{1,}
                // Em seguida, você deve criar um ponteiro para o início da constante
                const char *pModemReceiveRtc = &MODEM_RECEIVE_RTC[ 0 ];

                // Configurando a classe
                // 1° elemento, quantidade máxima de passos necessário para comprir a tarefa + 1;
                // 2° elemento, quantidade máxima de espaços na memória para arquivar dados enviados/recebidos;
                // 3° elemento, quantidade máxima de funções a serem executadas antes do envio dos dados;
                SendToDevice<const char, char, unsigned char, unsigned char> *sd = new SendToDevice<const char, char, unsigned char, unsigned char>( 10, 5, 5 );

                // Existe a necessidade de enviar dados pela porta serial, um de cada vez?
                // 1° elemento, ponteiro de função tipo void ( *p ) ( template )
                sd->setSendFunction( &sendFunction );

                // O dado a ser enviado não necessita de uma função de envio, mas, necessita de um buffer para ser arquivado
                // enquanto o mesmo não é enviado.
                sd->setSendToDataPointer( &bufferAddress, unsigned int buffer size - 1 );
                sd->setOnBufferFullFunction( &onBufferFullFunction );

                // Para todos os comandos a serem enviados e recebidos, você repetirá os passos abaixo.
                // Limpe a memória da classe
                sd->clear();

                // O retorno do modem será +CCLK: "09/10/15,19:33:42+00"\r\n
                // Ou seja, data, fora e fuso horário.
                // Nossa constante tem: {time}, {time} e {snum}
                //                      addr 0, addr 1 e addr 2
                // na ordem que aparecem
                sd->addPointer( 0, &array_char_data[ 0 ] );
                sd->addPointer( 1, &array_char_hora[ 0 ] );
                sd->addPointer( 2, &array_char_fuso_horario[ 0 ] );
                // Preparando o buffer de passos
                // Aponta para o comando a ser enviado.
                sd->addTransmitData( 0, &MODEM_SEND_COMMAND_GET_RTC[ 0 ] );
                // O modem vai devolver "OK\r\n", mas, este passo não é relevante, então vamos ignorar ele, apontando 0 para
                // o endereço da função a ser recebida.
                // O dado recebido deve ser usado para esperar por respostas tipo OK\r\n, que devem ser esperadas antes do
                // próximo envio de dados, mas, não são tratados.
                sd->addReceiveData( 0, 0 );
                // O último endereço da pilha deve receber zero para indicar o fim do envio.
                // Isto é obrigatório sempre.
                sd->addTransmitData( 1, 0 );
                sd->addReceiveData( 1, 0 );
                // Dispare o envio
                sd->run();

                // Todo uC necessita de um loop infinito para não trevar. Nesse loop, coloque a função abaixo
                sd->infinityLoop();

                // O próximo passo é criar uma função para receber os dados da porta serial, e dentro dela
                // colocar o código:

                char dado_serial = Serial.read(); // De a cordo com a sua plataforma.
                if ( sd->testPointer ( &pModemReceiveRtc, &MODEM_RECEIVE_RTC[ 0 ], dado_serial ) == ( char ) 1 )
                {
                  // A resposta do modem foi capturada
                }


       @endcode
     */
    static void init( typeStackStepsSize stackStepsSizeAUCh, typeStackDataSize stackDataSizeAUCh, typeStackStepsSize stackFunctionsSizeAUCh );
    SendToDevice();

    /**
     * @brief setSendFunction, recebe o ponteiro da função a ser chamada sempre que houver a necessidade de se enviar
     *        alguma coisa ao dispositivo. Perceba que este é um código OO e a regra básica da Orientação a Objeto diz para
     *        separar toda a lógica do acesso a hardware, por isto, você deve implementar uma função ou chamada de método
     *        estático de classe, fazer o acesso a hardware nele e apontar ele para esta classe.
     *
     * @param functPointerAPFn, este é um ponteiro de função do tipo void (*p)
     */
    static void setSendFunction ( PT_VOID_CH functPointerAPFn );

    /**
     * @brief setSendToDataPointer, aponta para um buffer externo, no caso, um array de char, onde fica o dado montado.
     *
     * @param toDataATplt, ponteiro do array de char.
     */
    static void setSendToDataPointer ( typeDataToMountBeforeExchange *toDataATplt );

    /**
     * @brief setSendToDataPointer, aponta para um buffer externo, no caso, um array de char, onde fica o dado montado.
     *
     * @param toDataATplt, ponteiro do array de char.
     *
     * @param lengthAUInt, tamanho do buffer. Deve receber sizeof( buffer ) - 1, o último dado é sempre '\0'
     */
    static void setSendToDataPointer ( typeDataToMountBeforeExchange *toDataATplt, unsigned int lengthAUInt );

    /**
     * @brief setOnEndFunction, recebe o ponteiro da função a ser chamada ao fim do processo de envio.
     *
     * @param functPointerAPFn, este é um ponteiro de função do tipo void ()
     */
    static void setOnEndFunction ( PT_VOID_VOID functPointerAPFn );

    /**
     * @brief setOnBufferFullFunction, recebe o ponteiro da função a ser chamada quando o buffer estiver cheio.
     *
     * @param functPointerAPFn, este é um ponteiro de função do tipo void ()
     */
    static void setOnBufferFullFunction ( PT_VOID_VOID functPointerAPFn );

    /**
     * @brief onIncomingData, Este método deve ser usado sempre que um novo dado chegar pela porta serial para que o mesmo
     *        possa ser tratado.
     *
     * @param inDataATplt, dado recebido pela porta serial.
     */
    static void onIncomingData ( typeDataToExchange inDataATplt );

    /**
     * @brief testPointer, este método deve ser usado para gerar eventos sempre que uma determinada constante chegar pela
     *        porta serial e deve ser usado no mesmo método que recebe o método onIncomingData().
     *
     *        O funcionamento dele é simples. Imagine que você está procurando na porta serial o texto "+ligar luz" para
     *        ligar uma luz. O primeiro parâmetro é o ponteiro constante para o array de char "+ligar a luz" e o segundo um
     *        ponteiro variável para o início do mesmo array de char. A medida que os dados forem chegando pela porta serial,
     *        o ponteiro variável vai varrendo a constante e quando o mesmo encontrar \0, fim  de texto, o método retorna o
     *        valor decimal 1. Qualquer valor negativo indica um erro na constante recebida.
     *
     *        Este método trabalha em conjunto com o método addPointer() para permitir a captura de dados em formatos
     *        específicos. Veja a lista abaixo.
     *
     *        {time} - Captura data/hora, formato: [0-9]{1,}[:/][0-9]{1,}[:/][0-9]{1,}
     *        {inum} - Ignora número, formato: [^0-9]{1,}
     *        {snum} - Captura número, formato: [0-9+-]{1,}
     *        {num}  - Captura número, formato: [0-9]{1,}
     *        {hex}  - Captura número, formato: [0-9a-fA-F]{1,}
     *        {str}  - Captura texto, formato: [0-9a-z(sp)]{1,}
     *        {istr} - Ignora texto, formato: [^0-9a-z(sp)]{1,}
     *        {all}  - Captura tudo, formato: [^\r\n\0]
     *
     *        Ex: Imagine o recebimento da string "+ligar luz 20\r\n"
     *            Ela ficaria: "+ligar luz {num}\r\n"
     *            Onde addPointer() apontaria para onde escrever o número contido na string.
     *
     * @param apcchPointer, ponteiro para a constante array de char com o texto procurado.
     *
     * @param apcchPointerStart, ponteiro movimentado pelo método para indicar o próximo caractere esperado.
     *
     * @param inDataATplt, dado da porta serial.
     *
     * @return interio convertido em signed char. négativo indica erro na constante recebida em relação a esperada, zero não é
     *         nada e um positivo indica constante encontrada.
     */
    static char testPointer ( typeDataToExchange **apcchPointer, typeDataToExchange *apcchPointerStart, typeDataToMountBeforeExchange inDataATplt );

    /**
     * @brief clear, limpa todos os ponteiros na pilha de dados a serem enviados.
     */
    static void clear ();

    /**
     * @brief addReceiveData, indica qual é o dado esperado na porta serial antes do próximo envio. Caso não haja a necessidade de
     *        resposta, este valor deve obrigatoriamente ser 0 ou '\0'.
     *        Perceba que para cada ponteiro de dado enviado, um ponteiro de dado esperado deve ser inicializado, ou a classe não
     *        funcionará de foma correta.
     *
     * @param addressATplt, inteiro positivo, iniciado em zero, com o endereço da memória. Caso seja passado um valor maior do
     *        que o valor máximo previsto na inicialização da classe, o mesmo será ignorado.
     *
     * @param dataAddressAPTplt, endereço do dado a ser comparado no recebimento.
     */
    static void addReceiveData ( typeStackStepsSize addressATplt, typeDataToExchange *dataAddressAPTplt );

    /**
     * @brief addTransmitData, Indica qual o endereço do dado a ser enviado pela porta serial. Neste ponto, perceba que a classe
     *        continuará enviando dado até encontrar um endereço onde endereço do dado a ser enviado ser 0, ou '\0', e por isto,
     *        você tem duas opções, dá um clear() antes de montar os dados a serem enviados, opção mais lenta, ou sempre que
     *        montar os dados a serem enviados, adicionar um último dado com valor 0 no endereço posterior ao último dado a ser
     *        enviado.
     *
     *        Ex. addTransmitData( 5, '\0' );
     *            addReceiveData( 5, '\0' );
     *
     * @param addressATplt, inteiro positivo, iniciado em zero, com o endereço da memória. Caso seja passado um valor maior do
     *        que o valor máximo previsto na inicialização da classe, o mesmo será ignorado.
     *
     * @param dataAddressAPTplt, endereço do dado a ser transmitido.
     */
    static void addTransmitData ( typeStackStepsSize addressATplt, typeDataToExchange *dataAddressAPTplt );

    /**
     * @brief addPointer, todos os dados recebidos podem ser separados conforme falado na função testPointer() e todo dado enviado
     *        pode ser montado conforme descrito na função run().
     *
     *        Para isto, você deve adicionar ponteiros para arrays de char, na ordem que eles aparecem nos dados a serem
     *        transmitidos ou recebidos. Apenas tome cuidado de usar arrays de char suficientemente longos para receber os dados,
     *        ou o sistema pode travar.
     *
     * @param addressATplt, ordem dos dados encontrados começando em zero.
     *
     * @param dataAddressAPTplt, ponteiro do dado.
     */
    static void addPointer ( typeStackDataSize addressATplt, typeDataToMountBeforeExchange *dataAddressAPTplt );

    /**
     * @brief addFunctionData, o dado enviado pode ser usado para rodar uma função interna do uC e atualizar alguma informação
     *        qualquer antes do envio da mesma.
     *
     * @param addressATplt, endereço da função na pilha.
     *
     * @param functionAddressAPTplt, endereço da função.
     */
    static void addFunctionData ( typeStackStepsSize addressATplt, PT_VOID_VOID functionAddressAPTplt );

    /**
     * @brief infinityLoop, coloque esta função de forma que ela fique sendo chamada sempre, independente de haver dados ou não.
     */
    static void infinityLoop ();

    /**
     * @brief run, inicia o processo de envio de dados.
     *
     *        Este método trabalha em conjunto com o método addPointer() para formatar os dados a serem enviados.
     *        {pt}   - indica o próximo ponteiro da dado a ser enviado;
     *        {ad:n} - é o mesmo que {pt}, porém, n representa o endereço da pilha;
     *        {fn:n} - executa uma função previamente registrada no endereço n, antes do envio do dado.
     *        {bye}  - char( 1A ), usado nas funções do motem baseados em comandos AT.
     */
    static void run ();

    /**
     * @brief lembre-se de destruir a classe e limpar a memória.
     */
    static void destructor();

  //private:
    /**
     * @brief flagSet, setBit(). A linguagem C/C++ usa um byte interio para booleano, este método usa 1 byte para 8 booleanos.
     *
     * @param flagACh, valor entre 0 e 7 com o endereço do bit.
     */
    static void flagSet ( char flagACh );

    /**
     * @brief flagClear, clearBit(). A linguagem C/C++ usa um byte interio para booleano, este método usa 1 byte para 8 booleanos.
     *
     * @param flagACh, valor entre 0 e 7 com o endereço do bit.
     */
    static void flagClear ( char flagACh );

    /**
     * @brief flagTest, testBit(). A linguagem C/C++ usa um byte interio para booleano, este método usa 1 byte para 8 booleanos.
     * @param flagACh, valor entre 0 e 7 com o endereço do bit.
     * @return true ou false com o valor do bit.
     */
    static bool flagTest ( char flagACh );

    /**
     * @brief send, processa o dado.
     */
    static void send ();

    /**
     * @brief bufferLengthCUInt, tamanho do array de dados a serem recebidos ou transmitidos.
     */
    static unsigned int bufferLengthCUInt;

    static PT_VOID_VOID onBufferFullCPFnc;
    static PT_VOID_VOID onEndCPFnc;
    static PT_VOID_CH sendCPFnc;
    static typeDataToMountBeforeExchange *sendToData;
    static typeDataToMountBeforeExchange *sendToDataOriginal;

    static char flagsCCh;

    static PT_VOID_VOID *functionToExecuteCPFnc;
    static typeDataToMountBeforeExchange **dataToMountCPTplt;
    static typeDataToExchange **dataTransmitCPTplt;
    static typeDataToExchange **dataReceiveCPTplt;

    static typeStackStepsSize stackStepsSizeCTplt;
    static typeStackDataSize stackDataSizeCTplt;
    static typeStackStepsSize stackFunctionsSizeCTplt;

    static typeStackDataSize dataListLineCTplt;
    static typeStackStepsSize dataTransmitPointerLineCTplt;
    static typeStackStepsSize dataReceivePointerLineCTplt;
};

template class SendToDevice<const char, char, unsigned char, unsigned char>;
template class SendToDevice<const unsigned char, unsigned char, unsigned char, unsigned char>;

#endif // SENDTODEVICE_H
