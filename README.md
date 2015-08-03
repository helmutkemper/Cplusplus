## Cplusplus

### Caia na real com Arduino

Eu tenho visto muitas pessoas falando muito bem do Arduino e outras falando muito mal do Arduino.

No meu ponto de vista, entenda o seguinte:

Tudo na vida tem um lado bom e um lado ruim. Aprenda a transforma o lado ruim em força e siga em frente.

O lado ruim do Arduino:

1. É lento, só tem 16MHz;
2. Tem pouca memória;
3. As classes prontas não são eficientes na utilização de memória.

Antes de continuar entenda o fato de não existir um hardware Arduino, o que existe de verdade é um hardware AVR seguindo os padrões do projeto Arduino. Você deve ter a capacidade de saber a diferença e poder separar as duas coisas.

As três fraquezas citadas acima são suas melhores amigas para se tornar um programador melhor. Aprenda a fazer um código leve, eficiente e com baixo consumo de memória para rodar em um Arduino barato e você poderá rodar em qualquer plataforma existente no mercado com folga.

Por isto, saia da sua zona de conforto e vá procurar a dificuldade. Ela é sua amiga e te ajuda a transformar fraqueza em força.

Muitos vão falar mal do Arduino e de C/C++ e vão partir para linguagens de programação que são basicamente um framework pronto. Cuidado com isto. Antes de partir para está abordagem se lembre de duas regras simples:

1. Você já tem capacidade de fazer do zero e só está ganhando tempo?
2. A linguagem escolhida é a melhor para o projeto ou para você? Por exemplo, pyton é mais fácil do que C/C++, porém, é 100x mais lento e requer a instalação de uma máquina virtual para rodar.

### Dicas de programação.

Quando se trabalha com com C++ para hardware deve-se tomar cuidado no uso excessivo de ponteiros para a inicialização de classes, por isto, a maioria das classes são estáticas. Isto poupa memória e tempo de execução.

Uma outra coisa muito importante é o fato de você necessitar criar funções externas a classe sempre que uma função específica do hardware for usada.

Na prática, o código fica dividido em camadas, como na orientação a objeto, porém, a sua classe genérica nunca conterá acesso direto ao hardware ou configuração específica do mesmo. Quando isto for necessário você deve criar um ponteiro de função e fazer a sua classe genérica chamar uma função externa com esta finalidade.

Por isto é comum em minhas classes haver o uso de ponteiros para funções como no exemplo abaixo.

```
extern "C"
{
  typedef void ( * StatusModem ) ( eEvent );
  typedef void ( * ExternalDataModem ) ( char );
  typedef void ( * Action ) ();
}
```

Caso você não esteja familiarizado com este tipo de construção da linguagem, por favor, pare e estude sobre isto antes de continuar. É de vital importância o entendimento da construção de ponteiros para se trabalhar bem com hardware.

Ao contrário do que diz a lenda sobre ponteiros, eles não são complicados de serem usados e ajudam a poupar tempo de processamento e memória do hardware. Fazendo com que sua compreensão seja de vital importância para qualquer programador de hardware.

### Máquinas de estados finitos:

Máquina de estados é um excelente forma de manter o código organizado, principalmente quando o código é complexo e necessita de muitas etapas a serem cumpridas antes de uma tarefa ser executada. Por isto, muitos códigos que trabalham com dispositivos seriais são baseados em máquinas de estado e a conclusão das tarefas gera um evento.

Por padrão, eu costumo usar enumerador para eventos e o mesmo costuma ficar dentro do namespace Event e são processados pela função Classe::OnEvent().

Porém, não encare a máquina de estados como solução final para tudo, ela organiza muito bem o código, mas, ela requer memória e tempo de processamento. Por isto, use com sabedoria.

Como usar a máquina de estados:

A máquina de estados do código foi feita para trabalhar com comandos AT, onde uma string formatada é enviada e recebida o tempo todo para cada comando e você deve ter isto em mente na hora do uso.

Por uma simples questão de memória RAM e tempo de processamento, o código não arquiva nada que chegou para depois tratar. Ele varre uma série de ponteiros e compara o que chegou com o esperado e executa uma ação quando algo bate.

Por isto, você necessita criar constantes com o texto procurado e um ponteiro individual para cada texto procurado.

```
1. Crie as constantes a serem enviadas por serial na forma de constante de array de char, assim:
const char AtModem::kReceiveCmti[] = { "+CMTI: \"SM\",{pSMS}\0" };
2. Crie um ponteiro para o início da string a ser enviada.
const char *AtModem::pReceiveCmt = &AtModem::kReceiveCmt[ 0 ];
```

Repita os passos acima para cada comando necessário. Em seguida, crie uma função para disparar a lista de comandos necessários para a tarefa.

```
1. Crie uma função
void AtModem::SmsSend ()
{
  2. Adicione um ponteiro para o primeiro comando a ser enviado pela porta serial
  AtModem::pDataTxToModem[ 0 ] = &AtModem::kSendEchoOff[ 0 ];
  3. Adicione a resposta esperada.
  AtModem::pDataRxToModem[ 0 ] = &AtModem::kReceiveOk[ 0 ];

  4. Repita os passos quantas vezes por necessário.
  5. Caso não seja necessário esperar uma resposta, coloque 0x00 em Rx.
  AtModem::pDataTxToModem[ 1 ] = &AtModem::kSendSmsTextMode[ 0 ];
  AtModem::pDataRxToModem[ 1 ] = &AtModem::kReceiveOk[ 0 ];

  AtModem::pDataTxToModem[ 2 ] = &AtModem::kSendSmsSendConfig[ 0 ];
  AtModem::pDataRxToModem[ 2 ] = &AtModem::kReceiveSmsTextRedyToSend[ 0 ];

  AtModem::pDataTxToModem[ 3 ] = &AtModem::kSendSmsSendText[ 0 ];
  AtModem::pDataRxToModem[ 3 ] = &AtModem::kReceiveOk[ 0 ];

  AtModem::pDataTxToModem[ 4 ] = &AtModem::kSendEchoOff[ 0 ];
  AtModem::pDataRxToModem[ 4 ] = &AtModem::kReceiveOk[ 0 ];

  6. Deixe os ponteiros do último estágio com o valor 0x00 OBRIGATORIAMENTE!
  AtModem::pDataTxToModem[ 5 ] = '\0';
  AtModem::pDataRxToModem[ 5 ] = '\0';

  7. Ligue a máquina.
  AtModem::StateMachineResetAndRun ();
}
```
Para os comandos de envio, use:

1. {pt}  - Ponteiro de onde os dados estão
2. {bye} - Envia o byte 'bye' ( 0x1A ) ao fim da transmissão de dados. Usado para envio de SMS e conexão com a internet.

Para os dados recebidos use:

1. {time} - Captura data/hora, formato: [0-9]{1,}[:/][0-9]{1,}[0-9]{1,}[:/]
2. {inum} - Ignora número, formato: [^0-9]{1,}
3. {snum} - Captura número, formato: [0-9+-]{1,}
4. {num}  - Captura número, formato: [0-9]{1,}
5. {hex}  - Captura número, formato: [0-9a-fA-F]{1,}
6. {str}  - Captura texto, formato: [0-9a-z(sp)]{1,}
7. {istr} - Ignora texto, formato: [^0-9a-z(sp)]{1,}
8. {all}  - Captura tudo, formato: [^\r\n\0]

Exemplos de uso:
```
Esta função envia é um exemplo real e envia SMS para um determinado número.
void SmsSendAfterEvent ()
{
  1. O primeiro ponteiro necessário é para o número de telefone.
  AtModem::pDataList[ 0 ] = &SmsTelefon[ 0 ];

  2. O segundo ponteiro é para a mensagem a ser enviada.
  AtModem::pDataList[ 1 ] = &chTextSendAfterEvent[ 0 ];

  3. Chama a função de envio de SMS.
  AtModem::SmsSend();
}
```

Passo a passo temos:
```
> O protocolo pede que se espere um "OK\r\n" para se mandar o próximo comando.
const char AtModem::kReceiveOk[] = { "OK\r\n\0" };

> Como eu disse, o código sempre pode melhorar e este comando poderia ser enviado uma única vez no evento power on
const char AtModem::kSendEchoOff[] =  { "ATE0\r\n\0" };

> Coloca o modem em moto texto. Na prática do dia a dia, faça isto sempre.
const char AtModem::kSendSmsTextMode[] = { "AT+CMGF=1\r\n\0" };

> Perceba que dentro da string contem o modificador {pt} e este modificador fará o programa enviar a string contida dentro do ponteiro "AtModem::pDataList[ N ]" do exemplo anterior, onde N representa um número inteiro de acordo com a ordem dos dados a serem passados.
> Nesse caso, o protocolo do modem espera a string com o número para onde o SMS será enviado.
const char AtModem::kSendSmsSendConfig[] = { "AT+CMGS=\"{pt}\"\r\n\0" };

> O protocolo pede pela para esperar a string "> " antes de enviar o texto.
const char AtModem::kReceiveSmsTextRedyToSend[]	= { "> " };

> O modificador {pt} é usado, como no exemplo acima, para apontar para o texto a ser enviado.
> O modificador {bye} envia o comando de fim de texto, conforme o protocolo do modem.
const char AtModem::kSendSmsSendText[] = { "{pt}{bye}\0" };

void AtModem::SmsSend ()
{
  > Todos os passos são enviados conforme manda o manual do modem.
  AtModem::pDataTxToModem[ 0 ] = &AtModem::kSendEchoOff[ 0 ];
  AtModem::pDataRxToModem[ 0 ] = &AtModem::kReceiveOk[ 0 ];

  AtModem::pDataTxToModem[ 1 ] = &AtModem::kSendSmsTextMode[ 0 ];
  AtModem::pDataRxToModem[ 1 ] = &AtModem::kReceiveOk[ 0 ];

  AtModem::pDataTxToModem[ 2 ] = &AtModem::kSendSmsSendConfig[ 0 ];
  AtModem::pDataRxToModem[ 2 ] = &AtModem::kReceiveSmsTextRedyToSend[ 0 ];

  AtModem::pDataTxToModem[ 3 ] = &AtModem::kSendSmsSendText[ 0 ];
  AtModem::pDataRxToModem[ 3 ] = &AtModem::kReceiveOk[ 0 ];

  AtModem::pDataTxToModem[ 4 ] = &AtModem::kSendEchoOff[ 0 ];
  AtModem::pDataRxToModem[ 4 ] = &AtModem::kReceiveOk[ 0 ];

  AtModem::pDataTxToModem[ 5 ] = '\0';
  AtModem::pDataRxToModem[ 5 ] = '\0';

  AtModem::StateMachineResetAndRun ();
}
```

Quando o SMS for enviado, o evento "Event::EndProcess" será disparado.

### Dica para virar um bom programador

Pare de escutar as pessoas que nunca programaram quando elas falam sobre programação;

Deixe seu orgulho de lado e entenda de uma vez por todas, seu código pode ser feito de forma melhor. Tenha sempre isto em mente;

Quando fizer um programa, pare analise e refaça o mesmo do zero até o dia que a próxima versão não ficar tão melhor do que a anterior;

Programe por programar, apenas pelo desafio de fazer. Esta é a única forma de aprender a programar;

As regras de orientação a objetos são muito mais do que teoria e devem ser absorvidas. Pratique e refaça seus códigos até a orientação a objeto deixar de ser uma teoria e passar a ser uma forma de pensar cotidiana;

Você só será um programador quando seus erros forem fáceis de corrigir e seus códigos desorganizados forem fáceis de entende e corrigir por qualquer pessoa;

Não se julgue um bom programador. Você ainda está vivo e pode fazer melhor;
Programação de verdade vai muito além de fazer funcionar. É necessário fazer funcionar da maneira certa e realmente saber o que está fazendo. Programação é uma ciência exata e não tem espaço para "eu acho...".

### Licença de uso

Este repositório tem a finalidade de ajudar programadores de hardware a entenderem melhor programação C++ para as necessidades
de hardware, possibilitando a criação de códigos C++ livres de plataforma, onde o mesmo código deve rodar em uma placa Arduino
simples e também em um Linux ( x86, x64, ARM ), Mac Os X e Windows.

Todos os códigos são distribuídos com o intúito de ajudar, porém, são distribuídos sem garantia de funcionamento ou obrigação
de suporte de qualquer tipo de minha parte.

Você é livre para copiar, modificar e distribuir meu código livremente, porém, sempre que fizer algum tipo de alteração deve 
deixar claro o fato de não ser o meu código original e tem a obrigação de mencionar meu nome como desenvolvedor original.

Helmut Kemper
helmut.kemper@gmail.com
