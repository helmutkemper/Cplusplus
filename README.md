## Cplusplus


### Caia na real com Arduino

Eu tenho visto muitas pessoas falando muito bem do Arduino e outras falando muito mal do Arduino.

No meu ponto de vista, entenda o seguinte:

Tudo na vida tem um lado bom e um lado ruim. Aprenda a transforma o lado ruim em força e siga em frente.

O lado ruim do Arduino:

1. É lento, só tem 16MHz;
2. Tem pouca memória;
3. As classes prontas não são eficientes na utilização de memória.

Antes de continuar entenda o fato de não existir um hardware Arduino, o que existe de verdade é um projeto baseado no uC AVR da Atmel, seguindo os padrões do projeto de nome Arduino. Você deve ter a capacidade de saber a diferença e poder separar as duas coisas.

As três fraquezas citadas acima são suas melhores amigas para se tornar um programador melhor. Aprenda a fazer um código leve, eficiente e com baixo consumo de memória para rodar em um Arduino barato e você poderá rodar em qualquer plataforma existente no mercado com folga.

Por isto, saia da sua zona de conforto e vá procurar a dificuldade. Ela é sua amiga e te ajuda a transformar fraqueza em força.

Muitos vão falar mal do Arduino e de C/C++ e vão partir para linguagens de programação que são basicamente um framework pronto. Cuidado com isto. Antes de partir para esta abordagem, lembre-se de duas regras simples:

1. Você já tem capacidade de fazer do zero e só está ganhando tempo?
2. A linguagem escolhida é a melhor para o projeto ou para você? Por exemplo, Python é mais fácil do que C/C++, porém, é 100x mais lento e requer a instalação de uma máquina virtual para rodar.


### Dicas de programação.

Quando se trabalha com com C++ para hardware deve-se tomar cuidado no uso excessivo de ponteiros para a inicialização de classes, por isto, a maioria das classes são estáticas. Isto poupa memória e tempo de execução. Mas, quando criar os ponteiros, lembre-se de os destruir ao final do uso.

Uma outra coisa muito importante é o fato de você necessitar criar funções externas a classe sempre que uma função específica do hardware for usada.

Na prática, o código fica dividido em camadas, como na orientação a objeto, porém, a sua classe genérica nunca conterá acesso direto ao hardware ou configurações específicas do mesmo. Quando isto for necessário, você deve criar um ponteiro de função e fazer a sua classe genérica chamar uma função externa com esta finalidade.

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

Ao contrário do que diz a lenda sobre ponteiros, eles não são complicados de serem usados e ajudam a poupar tempo de processamento e memória do hardware. Fazendo com que sua compreensão seja de vital importância para qualquer programador de hardware, por isto, pare e pratique o uso de ponteiros até realmente entender o que está fazendo e deixe as lendas de lado.

Lembre-se, você está trabalhando com exatas e não há espaço para lendas ou achismos, ou você sabe, ou você deve estudar mais.


### Máquinas de estados finitos:

Máquina de estados é uma excelente forma de manter o código organizado, principalmente quando o código é complexo e necessita de muitas etapas a serem cumpridas antes de uma tarefa ser executada. Por isto, muitos códigos que trabalham com dispositivos seriais são baseados em máquinas de estado e a conclusão das tarefas gera um evento.

Por padrão, eu costumo usar enumerador para eventos e o mesmo costuma ficar dentro do namespace Event e são processados pelo método NomeDaClasse::OnEvent().

Não encare a máquina de estados como solução final para tudo, ela organiza muito bem o código, mas, ela requer memória e tempo de processamento. Por isto, use com sabedoria.


#### Quando usar máquinas de estados:

Em alguns tipos de aplicações, geralmente com dispositivos baseados em porta serial, os eventos acontecem de forma assíncrona e a velocidade dos dados de entrada é infinitamente baixa em relação a velocidade de processamento da plataforma, assim a máquina de estados deixa a plataforma livre para trabalhar enquanto o dado esperado não chega por completo. A outra funcionalidade dela é arquivar uma lista de passos a serem executados para se cumprir uma tarefa.
 
Nesse ponto, imagine um modem GPRS executado um programa controlado por SMS para interagir com o usuário. O protocolo do modem baseado em comandos AT necessita passar uma série de comandos, e a cada comando dado o mesmo deve responder algo antes do próximo comando ser enviado. Assim, há uma lista de passos a serem executados antes de um SMS ser enviado ou lido e a máquina de estados é excelente para organizar o código e deixar a plataforma livre para outras tarefas enquanto processa as necessidades do protocolo do modem. 


##### Como usar a máquina de estados:

A máquina de estados do código foi feita para trabalhar com o envio e recebimento de strings fixas, onde uma string formatada é enviada e recebida o tempo todo para cada comando e você deve ter isto em mente na hora do uso.

Por uma simples questão de memória RAM e tempo de processamento, o código não arquiva nada que chega para depois tratar. Ele varre uma série de ponteiros e compara o que chegou com o esperado e executa uma ação quando algo bate.

Por isto, você necessita criar constantes com o texto procurado e um ponteiro individual para cada texto procurado.

```
// 1. Crie as constantes a serem enviadas por porta serial na forma de constante de array de char, assim:
// Descrição: +CMTI - New message indication
// Formato: +CMTI: "SM",n°\r\n
// pSMS foi criado dentro da classe para arquivar o id do SMS recebido.
const char AtModem::kReceiveCmti[] = { "+CMTI: \"SM\",{pSMS}\0" };
// 2. Crie um ponteiro para o início da string a ser enviada.
const char *AtModem::pReceiveCmt = &AtModem::kReceiveCmt[ 0 ];
```

Repita os passos acima para cada comando necessário. Em seguida, crie uma função para disparar a lista de comandos necessários para a tarefa.

```
// 1. Crie uma função
void AtModem::SmsSend ()
{
  // 2. Adicione um ponteiro para o primeiro comando a ser enviado pela porta serial
  AtModem::pDataTxToModem[ 0 ] = &AtModem::kSendEchoOff[ 0 ];
  // 3. Adicione a resposta esperada.
  AtModem::pDataRxToModem[ 0 ] = &AtModem::kReceiveOk[ 0 ];

  // 4. Repita os passos quantas vezes por necessário.
  // 5. Caso não seja necessário esperar uma resposta, coloque 0x00 em Rx.
  AtModem::pDataTxToModem[ 1 ] = &AtModem::kSendSmsTextMode[ 0 ];
  AtModem::pDataRxToModem[ 1 ] = &AtModem::kReceiveOk[ 0 ];

  AtModem::pDataTxToModem[ 2 ] = &AtModem::kSendSmsSendConfig[ 0 ];
  AtModem::pDataRxToModem[ 2 ] = &AtModem::kReceiveSmsTextRedyToSend[ 0 ];

  AtModem::pDataTxToModem[ 3 ] = &AtModem::kSendSmsSendText[ 0 ];
  AtModem::pDataRxToModem[ 3 ] = &AtModem::kReceiveOk[ 0 ];

  AtModem::pDataTxToModem[ 4 ] = &AtModem::kSendEchoOff[ 0 ];
  AtModem::pDataRxToModem[ 4 ] = &AtModem::kReceiveOk[ 0 ];

  // 6. Deixe os ponteiros do último estágio com o valor 0x00 OBRIGATORIAMENTE!
  AtModem::pDataTxToModem[ 5 ] = '\0';
  AtModem::pDataRxToModem[ 5 ] = '\0';

  // 7. Limpe e ligue a máquina de estados.
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
9. {pSMS} - Ponteiro da classe que aponta para o id do SMS recebido
10. {pSMG} - Ponteiro da classe que aponta para a mensagem recebida
11. {pTME} - Ponteiro da classe que aponta para a hora do SMS
12. {pDAY} - Ponteiro da classe que aponta para a data do SMS
13. {pPHO} - Ponteiro da classe que aponta para o número do telefone do SMS


#### Exemplos de uso 1:
```
Esta função é um exemplo real e envia SMS para um determinado número.
void SmsSendAfterEvent ()
{
  // 1. O primeiro ponteiro necessário é para o número de telefone.
  AtModem::pDataList[ 0 ] = &gchaSmsTelefon[ 0 ];

  // 2. O segundo ponteiro é para a mensagem a ser enviada.
  AtModem::pDataList[ 1 ] = &gchaTextSendAfterEvent[ 0 ];

  // 3. Chama a função de envio de SMS.
  AtModem::SmsSend();
}
```

Passo a passo temos:
```
// O protocolo pede que se espere um "OK\r\n" para se mandar o próximo comando.
const char AtModem::kReceiveOk[] = { "OK\r\n\0" };

// Como eu disse, o código sempre pode melhorar e este comando poderia ser enviado uma única vez no evento power on
const char AtModem::kSendEchoOff[] =  { "ATE0\r\n\0" };

// Coloca o modem em moto texto. Na prática do dia a dia, faça isto sempre.
const char AtModem::kSendSmsTextMode[] = { "AT+CMGF=1\r\n\0" };

// Perceba que dentro da string contem o modificador {pt} e este modificador fará o programa enviar a string
// contida dentro do ponteiro "AtModem::pDataList[ n° ]" do exemplo anterior, onde n° representa um número
// inteiro de acordo com a ordem dos dados a serem passados.
// Nesse caso, o protocolo do modem espera a string com o número para onde o SMS será enviado.
const char AtModem::kSendSmsSendConfig[] = { "AT+CMGS=\"{pt}\"\r\n\0" };

// O protocolo pede pela para esperar a string "> " antes de enviar o texto.
const char AtModem::kReceiveSmsTextRedyToSend[]	= { "> " };

// O modificador {pt} é usado, como no exemplo acima, para apontar para o texto a ser enviado.
// O modificador {bye} envia o comando de fim de texto, conforme o protocolo do modem.
const char AtModem::kSendSmsSendText[] = { "{pt}{bye}\0" };

void AtModem::SmsSend ()
{
  // Todos os passos são enviados conforme manda o manual do modem.
  AtModem::pDataTxToModem[ 0 ] = &AtModem::kSendEchoOff[ 0 ];
  AtModem::pDataRxToModem[ 0 ] = &AtModem::kReceiveOk[ 0 ];

  AtModem::pDataTxToModem[ 1 ] = &AtModem::kSendSmsTextMode[ 0 ];
  AtModem::pDataRxToModem[ 1 ] = &AtModem::kReceiveOk[ 0 ];

  AtModem::pDataTxToModem[ 2 ] = &AtModem::kSendSmsSendConfig[ 0 ];
  AtModem::pDataRxToModem[ 2 ] = &AtModem::kReceiveSmsTextRedyToSend[ 0 ];

  AtModem::pDataTxToModem[ 3 ] = &AtModem::kSendSmsSendText[ 0 ];
  AtModem::pDataRxToModem[ 3 ] = &AtModem::kReceiveOk[ 0 ];

  AtModem::pDataTxToModem[ 4 ] = '\0';
  AtModem::pDataRxToModem[ 4 ] = '\0';

  AtModem::StateMachineResetAndRun ();
}
```

Quando o SMS for enviado, o evento "Event::EndProcess" será disparado.


#### Exemplos de uso 2:

```
// Pegar a informação contida no RTC e arquivar dentro dos arrays de char day, clock e time zone.
AtModem::pDataList[ 0 ] = &chaDay[ 0 ];
AtModem::pDataList[ 1 ] = &chaClock[ 0 ];
AtModem::pDataList[ 2 ] = &chaTimeZone[ 0 ];
AtModem::RtcGet();
```

Passo a passo temos:
```
// O protocolo manda envia o comando "AT+CCLK?\r\n".
const char AtModem::kSendCclk[] = { "AT+CCLK?\r\n\0" };

// A resposta será data na forma de string como no exemplo abaixo:
// +CCLK: "00/01/01,03:58:08+00"\r\n
// Por isto, foram usados os modificadores {time} e {snum} para determinar o tipo de dado esperado.
const char AtModem::kReceiveCclk[] = { "+CCLK: \"{time},{time}{snum}\0" };

// Ponteiro para início do dado esperado
const char *AtModem::pCclk = &AtModem::kReceiveCclk[ 0 ];

// Função real usada para capturar a data e hora atual
// Detalhes explicados acima.
void AtModem::RtcGet ()
{
  AtModem::pDataTxToModem[ 0 ] = &AtModem::kSendCclk[ 0 ];
  AtModem::pDataRxToModem[ 0 ] = '\0'; // '\0' e 0x00 são a mesma coisa

  AtModem::pDataTxToModem[ 1 ] = '\0';
  AtModem::pDataRxToModem[ 1 ] = '\0';

  AtModem::StateMachineResetAndRun ();
}
```

Para cada byte recebido pela porta serial é usada a função "AtModem::Get ( char achChar )" e esta função tem uma série de chamadas para a função
```
// __GetTest, eu uso dois _ quando não quero criar uma função estática de uso "privado".
// Na ordem dos parâmetros, temos:
// Ponteiro de início da string esperada;
// Apontador para a string esperada;
// Byte recebido pela porta serial;
// Evento a ser disparado.
AtModem::__GetTest ( &AtModem::pCclk, &AtModem::kReceiveCclk[ 0 ], achChar, Event::RTCRead );
```


#### Exemplos de uso real para a classe do modem

```
void setup()
{
  // Configure tudo o que necessitar
  // Configure a porta serial
  Serial1.begin( 115200 );

  // Crie as variáveis abaixo para arquivar o SMS.
  // Não há necessidade disso na maioria dos casos, mas, esta classe foi feita
  // Originalmente para um cliente e a sua aplicação necessitava.
  // '[a|g|l]' indica o escopo [argumento de método|global|local], 'ch' indica o tipo char e 'a' indica o modificador array, ou seja, 'gcha' é um array de char global.
  // Resumindo: escopo + tipo [+ modificador]
  AtModem::pchSmsNew     = &gchaSmsIdNew[ 0 ];
  AtModem::pchCmtPhone   = &gchaSmsTelefon[ 0 ];
  AtModem::pchCmtDay     = &gchaSmsDate[ 0 ];
  AtModem::pchCmtTime    = &gchaSmsTime[ 0 ];
  AtModem::pchCmtMessage = &gchaSmsText[ 0 ];

  // Crie uma função para enviar os dado.
  // Veja o exemplo mais abaixo.
  AtModem::DataSendEvent = &fnDadoEnviado;
  
  // Inicialize a classe
  AtModem::Init ();
}
```

```
// No caso do Arduino:
// Crie uma função para enviar os dados da porta serial
// Como você pode perceber, a classe principal não faz acesso a hardware
// diretamente.
void fnDadoEnviado ( char achDado )
{
  Serial1.write ( achDado );
}
```

```
// No caso do Arduino:
// Para usar a porta serial 1, crie um evento para a porta serial
// Leia o dado e o transmita a classe do modem.
void serialEvent1 ()
{
  char lchDado = Serial1.read();
  AtModem::Get( lchDado );
}
```

```
// Adiciona uma nova entrada na agenda do SIM Card por endereço de memória
// Este método usa os arrays de char id, phone number e name que já devem estar populados quando 
// o método "AtModem::PhoneBookIdSet ()" for executado.
void PhoneBookAddById ()
{
  AtModem::pDataList[ 0 ] = &gchaId[ 0 ];
  AtModem::pDataList[ 1 ] = &gchaPhoneNumber[ 0 ];
  AtModem::pDataList[ 2 ] = &gchaName[ 0 ];
  AtModem::PhoneBookIdSet ();
}
```

```
void SmsSend ()
{
  AtModem::pDataList[ 0 ] = &gchaPhoneNumber[ 0 ];
  AtModem::pDataList[ 1 ] = &gchaTextToSend[ 0 ];
  AtModem::SmsSend();
}
```

```
void StatusRecebido ( Event::eEvent aenStatus )
{
  if ( aenStatus == Event::EndLine )
  {
    return;
  }

  switch ( aenStatus )
  {
    case Event::EndProcess:
      StateMachine::Step();
      break;

    case Event::SMSNew:
      // "AtModem::pchSmsNew" pertence a própria classe e é o id do SMS novo
      // para poder ser lido
      AtModem::pDataList[ 0 ] = AtModem::pchSmsNew;
      // Array de char para o status da mensagem
      AtModem::pDataList[ 1 ] = &gchaStatus[ 0 ];
      // Array de char para o telefone de onde o SMS foi enviado
      AtModem::pDataList[ 2 ] = &gchaTelefonNumber[ 0 ];
      // Array de char para a entrada da agenda contendo o telefone, caso seja
      // identificado
      AtModem::pDataList[ 3 ] = &gchaUserName[ 0 ];
      // Array de char para a data
      AtModem::pDataList[ 4 ] = &gchaDate[ 0 ];
      // Array de char para hora
      AtModem::pDataList[ 5 ] = &gchaTime[ 0 ];
      // Array de char para a zona de tempo
      AtModem::pDataList[ 6 ] = &gchaTimeZone[ 0 ];
      // Array de char para o texto da mensagem
      AtModem::pDataList[ 7 ] = &gchaText[ 0 ];
      // Repete o id da mensagem para que a mesma seja apagada
      AtModem::pDataList[ 8 ] = AtModem::pchSmsNew;
      // Vai disparar o evento "Event::SMSRead"
      AtModem::SmsReadAndDeleteById();
      break;

    case Event::SMSRead:
      // O SMS foi lido e os dados estão nos arrays de char citados acima.
      // Agora vamos supor que o SMS tem um texto específico para ser reconhecido.
      // "ligar o ar" e "desligar o ar" para ligar e desligar um ar condicionado.
      // Primeiro perceba que a palavra "ligar" está contida dentro da palavra "desligar",
      // por isto, vamos usar um "+" antes de cada comando.
      // Em algum lugar do código você criou
      // const char kReceiveLigarAr[] = { "+ligar ar\0" };
      // const char kReceiveDesligarAr[] = { "+desligar ar\0" };
      //
      // O comando acima arquivou o SMS no array de char "chaText"
      // Logo, as duas linhas abaixo vão testar e disparar o evento para as strings acima

      AtModem::Checker ( &kReceiveLigarAr[ 0 ], &chaText[ 0 ], Event::LigarAr );
      AtModem::Checker ( &kReceiveDesligarAr[ 0 ], &chaText[ 0 ], Event::DesligarAr );
      
      // Embora haja uma boa economia de memória se o texto do SMS for processado 
      // direto, arquivar o mesmo permite identificar o telefone de onde o mesmo partiu
      // permitindo implementar mais segurança ao processo.
  }
}
```

Dentro do seu código, crie a variável de evento.
```
Event::eEvent enMyEvent;
```

Depois, dentro do seu loop, use o seguinte código:
```
AtModem::StateMachineRun ();
lenMyEvent = StackEnum::Get();
StatusRecebido( lenMyEvent );
```


### Dica para virar um bom programador

Pare de escutar as pessoas que nunca programaram quando elas falam sobre programação;

Deixe seu orgulho de lado e entenda de uma vez por todas, seu código pode ser feito de forma melhor. Tenha sempre isto em mente;

Quando fizer um programa, pare analise e refaça o mesmo do zero até o dia que a próxima versão não fique tão melhor do que a anterior;

Programe por programar, apenas pelo desafio de fazer. Esta é a única forma de aprender a programar;

As regras de orientação a objetos são muito mais do que teoria e devem ser absorvidas. Pratique e refaça seus códigos até a orientação a objeto deixar de ser uma teoria e passe a ser uma forma de pensar cotidiana;

Você só será um programador quando seus erros forem fáceis de corrigir e seus códigos desorganizados forem fáceis de entende e corrigir por qualquer pessoa;

Não se julgue um bom programador. Você ainda está vivo e pode fazer melhor;

Programação de verdade vai muito além de fazer funcionar. É necessário fazer funcionar da maneira certa e realmente saber o que está fazendo. Programação é uma ciência exata e não tem espaço para "eu acho...".


### Licença de uso

Este repositório tem a finalidade de ajudar programadores de hardware a entenderem melhor programação C++ para as necessidades de hardware, possibilitando a criação de códigos C++ livres de plataforma, onde o mesmo código deve rodar em uma placa Arduino simples e também em um Linux ( x86, x64, ARM ), Mac Os X e [Ru]Windows.

Todos os códigos são distribuídos com o intuito de ajudar, porém, são distribuídos sem garantia de funcionamento ou obrigação de suporte de qualquer tipo de minha parte.

Você é livre para copiar, modificar e distribuir meu código livremente, porém, sempre que fizer algum tipo de alteração deve deixar claro o fato de não ser o meu código original e tem a obrigação de mencionar meu nome como desenvolvedor original.

Helmut Kemper
helmut.kemper@gmail.com
