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

/**
 *  @brief Esta classe tem a finalidade de fazer a troca de dados entre um hardware serial e um dispositivo AT, Modem e
 *         ODB-II, mas, também foi testada para se montar uma mini estrutura de servidor web montada em uma placa
 *         FRDM-K64F da Freescale ( http://www.freescale.com ) e testada na plataforma MBed ( http://www.mbed.org ).
 *
 *         Basicamente esta classe é uma máquina de estados feita para passar informações e esperar pela resposta do
 *         dispositivo.
 *
 *         Para isto imagine um modem baseado em protocolo AT, como o SIM900, muito comum em projetos Arduino. O
 *         protocolo consiste em passar mensagens de texto simples entre o hardware e o modem, de forma a gerar tarefas
 *         simples, como acessar internet ou passar e receber SMS.
 *
 *         No caso do envio de SMS pelo modem SIM900, o protocolo seria:
 *
 *         Enviar: AT+CMGF=1\r\n
 *         Receber: OK\r\n
 *         Enviar: AT+CMGS="número do telefone"\r\n
 *         Receber: >
 *         Enviar: mensagem de texto
 *         Enviar: char( 0x1A )
 *         Receber: OK\r\n
 *
 *         Como dá para ver, o existem uma série de pequenos passos a serem compridos, todos de forma síncrona, onde o
 *         próximo dado a ser transmitido necessita esperar para resposta de conclusão do passo anterior.
 *
 *         Antes de usar esta classe tenha em mente que a mesma foi testada em Arduino Mega e deve rodar independente
 *         da plataforma, e o template foi pensado para dados tipo char ou unsigned char, não tendo sido testado para
 *         string ou dados mais complexos.
 *
 *         A classe também prevê o a necessidade de se preparar um array de char antes do envio, onde uma constate pode
 *         perfeitamente ser montada de acordo com a necessidade da operação, sem maiores problemas.
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
     */
    SendToDevice( typeStackStepsSize stackStepsSizeAUCh, typeStackDataSize stackDataSizeAUCh );

    /**
     * @brief setSendFunction, recebe o ponteiro da função a ser chamada sempre que houver a necessidade de se enviar
     *        alguma coisa ao dispositivo. Perceba que este é um código OO e a regra básica da Orientação a Objeto diz para
     *        separar toda a lógica do acesso a hardware, por isto, você deve implementar uma função ou chamada de método
     *        estático de classe, fazer o acesso a hardware nele e apontar ele para esta classe.
     *
     * @param functPointerAPFn, este é um ponteiro de função do tipo void (*p)
     */
    void setSendFunction ( PT_VOID_CH functPointerAPFn );

    /**
     * @brief onIncomingData, Este método deve ser usado sempre que um novo dado chegar pela porta serial para que o mesmo
     *        possa ser tratado.
     *
     * @param inDataATplt, dado recebido pela porta serial.
     */
    void onIncomingData ( typeDataToExchange inDataATplt );

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
     *        Veja o resto da documentação da classe para mais detalhe.
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
    char testPointer ( typeDataToExchange **apcchPointer, typeDataToExchange *apcchPointerStart, typeDataToMountBeforeExchange inDataATplt );

    /**
     * @brief clear, limpa todos os ponteiros na pilha de dados a serem enviados.
     */
    void clear ();

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
    void addReceiveData ( typeStackStepsSize addressATplt, typeDataToExchange *dataAddressAPTplt );

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
    void addTransmitData ( typeStackStepsSize addressATplt, typeDataToExchange *dataAddressAPTplt );
    void addPointer ( typeStackDataSize addressATplt, typeDataToMountBeforeExchange *dataAddressAPTplt );
    void infinityLoop ();
    void run ();
    ~SendToDevice();

  private:
    void flagSet ( char flagACh );
    void flagClear ( char flagACh );
    bool flagTest ( char flagACh );
    void send ();

    PT_VOID_CH sendCPFnc;

    char flagsCCh;

    typeDataToMountBeforeExchange **dataToMountCPTplt;
    typeDataToExchange **dataTransmitCPTplt;
    typeDataToExchange **dataReceiveCPTplt;

    typeStackStepsSize stackStepsSizeCTplt;
    typeStackDataSize stackDataSizeCTplt;

    typeStackDataSize dataListLineCTplt;
    typeStackStepsSize dataTransmitPointerLineCTplt;
    typeStackStepsSize dataReceivePointerLineCTplt;
};

template class SendToDevice<const char, char, unsigned char, unsigned char>;
template class SendToDevice<const unsigned char, unsigned char, unsigned char, unsigned char>;

#endif // SENDTODEVICE_H
