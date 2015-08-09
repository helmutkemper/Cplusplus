#ifndef ATMODEM_H
#define ATMODEM_H

// Comente ou descomente estas constantes para definir qual funcionalidade você ira usar.
// Manter as funcionalidades comentadas poupa memória do hardware.

// Habilita conexão a internet e habilita pegar informação de geo possicionamento sem a 
// necessidade de GPS instalado
#define I_NEED_USE_INTERNET_FUNCTIONS

// Habilita o uso do PIN ( Personal Identification Number ) para o cartão SIM de celular.
#define I_NEED_SIM_PIN_FUNCTIONS

// Habilita os eventos de power on/off e o comando de power off
#define I_NEED_POWER_DOWN_FUNCTIONS

// Habilita as funções SMS. Perceba que SMS é barato e prático para o dia a dia e tem uma
// cobertura melhor do que GPRS, 3G e afins.
#define I_NEED_SMS_FUNCTIONS

// Habilita as funções de chamada do modem
#define I_NEED_CALL_FUNCTIONS

// Habilita a captura de latitude e longitude com baixa precisão. Perceba que os dados são submetidos a
// um site de terceiros e o mesmo pode mudar sem aviso prévio ou conter erros. Use por sua conta.
#define I_NEED_GEO_FUNCTIONS

// Habilita a agenda do cartão CIM
#define I_NEED_PHONEBOOK_FUNCTIONS

// Habilita as funções do RTC ( Real Time Clock ) do modem.
#define I_NEED_RTC_FUNCTIONS

// Habilita as funções de qualidade do sinal da operadora de celular.
#define I_NEED_QUALITY_FUNCTIONS

// Habilita os comandos de configuração assim que o modem liga
#define ENABLE_AUTO_POWER_ON_COMMANDS

// Habilita a desconexão imediata da internet caso ocorra algum erro. Esta função é muito útil, pois,
// as operadoras muitas vezes rejeitam a conexão e há ainda algumas particularides de alguns comandos AT
// onde o comando de desconexão ajuda. Mantenha esta constante descomentada por recomendação.
#define ENABLE_AUTO_INTERNET_DISCONECT

// Esta é outra constante importante de manter habilitada por recomendação.
#define ENABLE_AUTO_INTERNET_DISCONECT_AFTER_ERROR

// Define a quantidade de dígitos do header length.
// Quando o site faz uso do header length, o mesmo é usado para determinar o fim da conexão e gerar o evento.
// Ex. Content-Length: 3495
// @see http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html
#define kDefContentLength 5

// Nao mude nada a partir desse ponto
// Do not change anything from that point

#ifndef I_NEED_CALL_FUNCTIONS
  #undef ENABLE_AUTO_CALLER_NUMBER
#endif

#ifndef I_NEED_USE_INTERNET_FUNCTIONS
  #undef I_NEED_GEO_FUNCTIONS
  #undef ENABLE_AUTO_INTERNET_DISCONECT
  #undef ENABLE_AUTO_INTERNET_DISCONECT_AFTER_ERROR
#endif

#ifndef I_NEED_SMS_FUNCTIONS
  #undef ENABLE_AUTO_READ_AND_DELETE_SMS
#endif

#ifndef I_NEED_SMS_FUNCTIONS
  #undef ENABLE_AUTO_POWER_ON_COMMANDS
#endif

#ifndef I_NEED_SIM_PIN_FUNCTIONS
  #undef ENABLE_AUTO_PIN_ENABLE
#endif

// Define os flags permitindo que um único byte seja usado para arquivar 8bits.
// Economiza memória, porém, é mais lento do que o tipo Boolean, que usa um byte inteiro para cada bit.
#define kDefFlagRuning 0
#define kDefFlagNextStep 1
#define kDefFlagWaiting 2
#define kDefFlagInternetGet 3
#define kDefFlagCheckEnd 4

// Este enum é usado para ajudar na captura do header length.
// Quando o site faz uso do header length, o mesmo é usado para determinar o fim da conexão e gerar o evento.
// Ex. Content-Length: 3495
// @see http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html
namespace Step
{
  enum eStep
  {
    ContentLength1,
    ContentLength2,
    ContentLength3,
    Stop
  };
}
using namespace Step;

// Enum dos eventos do modem.
// Perceba que o uC usado para processar os dados do modem provavelmente é muito mais rápido do que a porta serial
// por onde os dados trafegam e há um atrazo entre o comando dado e o fim do mesmo, fazendo com que o código não seja
// lenear. Por isto, você deve usar os eventos para monitorar o fim de uma ação ou um possível erro.
namespace Event
{
  enum eEvent
  {
    // Modem livre.
    None,

    // Erro na captura de tempo
    PTimeError,

    // Erro na captura de número
    PNumError,

    // Erro na captura de número com sinal
    PSNumError,

    // Erro na captura de número hexadecimal
    PSHexError,

    // Erro na captura de string
    PStrError,

    // Erro na captura para p tipo all
    PAllError,

    // Erro na captura de id do novo SMS
    PSmsError,

    // Erro no ponteiro da mensagem
    PCmtMsgError,

    // Erro no ponteiro da hora
    PCmtTimeError,

    // Erro no ponteiro do dia
    PCmtDayError,

    // Erro no ponteiro do número de telefone
    PCmtPhoneError,

    // todo: root foi usado?
    #ifdef I_NEED_ROOT_FUNCTIONS
      RootEnable,
      RootDisable,
      RootAddData,
      RootDelData,
    #endif

    #ifdef I_NEED_USE_INTERNET_FUNCTIONS
      // Início da chegada dos dados
      InternetReadStart,

      // Fim da chegada dos dados
      InternetReadEnd,

      // Fim da conexão
      Close,

      // Erro de conexão
      ConnectionFailed,

      // Conexão
      InternetConnect,

      // Desconexão
      InternetDisconnect,
    #endif

    #ifdef I_NEED_GEO_FUNCTIONS
      // Captura dos dados internos do modem, a serem usados para o posicionamento
      EnginneringData,

      // ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
      EnginneringDataToGeo,
    #endif

    #ifdef I_NEED_PHONEBOOK_FUNCTIONS
      // Fim do processo de busca da agenda do modem.
      PhoneBookFind,
    #endif

    // Evento interno. Não use. Passo executado.
    EndLine,

    // Evento interno. Não use. Todos os passos executados.
    EndProcess,

    // Número do chamador capturado.
    CarrierNumberCaptured,

    // "telefone" tocando
    Ring,

    // Novo SMS recebido
    SMSNew,

    // SMS enviado com sucesso
    SMSSend,

    // SMS lido pos status
    SMSReadByStatus,

    // SMS lido
    SMSRead,

    // "SMS" da operadora de telefone lido.
    // São aquelas mensagens informando o saldo da conta e SPAN com propaganda da mesma, que nunca são arquivadas pelo modem.
    // Atenção: O modem não captura estas mensagens, por isto, as mesmas devem ser processadas de imediato ou serão perdidas.
    //          Na prática, quem liga?
    SMSCompanyRead,

    // ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
    SMSNumberAvailable,

    // ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
    SMSDeleted,

    // Evento de modem ligado
    PowerOn,

    // O SIM Card está pronto para uso
    SimReady,

    // O PIN do SIM Card é necessário
    SimPin,

    // O PUK do SIM Card é necessário.
    // Atenção: Não foi implementado nessa classe.
    SimPuk,

    // O PhPIN do SIM Card é necessário.
    // Atenção: Não foi implementado nessa classe.
    SimPhPin,

    // O PhPUK do SIM Card é necessário.
    // Atenção: Não foi implementado nessa classe.
    SimPhPuk,

    // Atenção: Não foi implementado nessa classe.
    SimPinNotFound,

    // Chamada não atendida
    NoCarrier,

    // O modem não consegue ligar
    NoDialTone,

    // Ligação não atendida
    NoAnswer,

    // Modem ou linha ocupadas
    Busy,

    // Erro.
    Error,

    // Modem pronto para uso
    CallReady,

    // O modem desligou
    PowerDown,

    // Qualidade do sinal da antena capturado
    SignalQuality,

    // RTC lido
    RTCRead,

    // Permite ao usuário criar seu próprio evento
    UserEvent1,

    // Permite ao usuário criar seu próprio evento
    UserEvent2,

    // RTC ajustado para a nova hora
    SetRtc
  };
}
using namespace Event;


extern "C"
{
  typedef void ( * StatusModem ) ( eEvent );
  typedef void ( * ExternalDataModem ) ( char );
  typedef void ( * Action ) ();
}

class AtModem
{
  public:

    #ifdef I_NEED_RTC_FUNCTIONS
      /** Ajusta o RTC do modem ( Real Time Clock ).
       * Exemplo: AT+CCLK ="12/12/26,15:04:50+08"\r\n\0
       */
      static const char kSendRtc[];

      /** Ponteiro para a string do RTC ( Real Time Clock )
       *
       */
      static const char *pSendRtc;

      /** Resposta do RTC do modem ( Real Time Clock )
       * Exemplo: +CCLK: "00/01/01,03:58:08+00"\r\n
       */
      static const char kReceiveCclk[];

      /** Comando de leitura do RTC ( Real Time Clock )
       * AT+CCLK?\r\n\0
       */
      static const char kSendCclk[];
      static const char *pCclk;

      /** Função para ajustar o RTC ( Real Time Clock )
       * \@code
          AtModem::pDataList[ 0 ] = &chaDate[ 0 ];     // Formato: YY/MM/DD\0 Exemplo: 15/12/30\0
          AtModem::pDataList[ 1 ] = &chaTime[ 0 ];     // Formato: hh:mm:ss\0 Exemplo: 10:31:55\0
          AtModem::pDataList[ 2 ] = &chaTimeZone[ 0 ]; // Formato: {+|-}NN\0  Exemplo: -03\0
          AtModem::RtcSet ();
       * \@endcode
       */
      void static RtcSet ();

      /** Função para leitura do RTC ( Real Time Clock )
       * \@code
          AtModem::pDataList[ 0 ] = &chaDate[ 0 ];
          AtModem::pDataList[ 1 ] = &chaTime[ 0 ];
          AtModem::pDataList[ 2 ] = &chaTimeZone[ 0 ];
          AtModem::RtcGet();
       * \@endcode
       */
      void static RtcGet ();
    #endif

    #ifdef I_NEED_POWER_DOWN_FUNCTIONS
      /** Envia o comando de power down do modem
       *  Exemplo: AT+CPOWD=1\r\n\0
       */
      static const char kSendPowerDown[];

      /** Recebimento do power on do modem.
       *  Este é o único indicador dos comandos AT, no modem usado para teste, que usa a tabela ASCII
       *  Exemplo: 0x49494949FEFEFEFE\0
       */
      static const char kReceivePowerOn[];
      static const char *pReceivePowerOn;

      /** Recebimento de indicador de power down.
       *  Exemplo: \r\nNORMAL POWER DOWN\r\n\0
       *  Na prática do modem usado para teste, ele começa e termina com \r\n.
       */
      static const char kReceiveNormalPowerDown[];
      static const char *pNormalPowerDown;

      /** Desliga o modem.
       *
       */
      void static PowerDown ();

      /** Configura o modem com os comandos básicos de uso assim que o modem fica ativo.
       *
       */
      void static OnModemPowerOn ();
    #endif

    #ifdef I_NEED_SIM_PIN_FUNCTIONS
      static const char kSendSinStatus[];
      static const char kSendSinPinUnlock[];
      static const char kSendSinPinLock[];
      static const char kSendSinPinChange[];
      static const char kSendSinPinEnter[];
      static const char kReceiveSimReady[];
      static const char kReceiveSimPin[];
      static const char kReceiveSimPuk[];
      static const char kReceiveSimPhPin[];
      static const char kReceiveSimPhPuk[];
      static const char *pReceiveSimReady;
      static const char *pReceiveSimPin;
      static const char *pReceiveSimPuk;
      static const char *pReceiveSimPhPin;
      static const char *pReceiveSimPhPuk;
      void static SimStatus ();
      void static SimEnterPin ();
      void static SimLockByPin ();
      void static SimUnlockByPin ();
      void static SimChangePin ();
    #endif

    #ifdef I_NEED_USE_INTERNET_FUNCTIONS
      static const char kSendIpSingle[];
      static const char kSendIpModeNormal[];
      static const char kSendDeactiveGprsDpd[];
      static const char kSendConnectHost[];
      static const char kSendStartSendData[];
      static const char kSendHeaderGetSend[];
      static const char kSendInternetDns[];
      static const char kSendInternetConnect[];
      static const char kSendInternerConnectPassword[];
      static const char kReceiveDeactiveGprsDpdOk[];
      static const char kReceiveContentLength[];
      static const char kReceiveHeaderGetSend[];
      static const char kReceiveConnectHost[];
      static const char kReceiveClose[];
      static const char kReceiveClosed[];
      static const char kReceiveConnectionFailed1[];
      static const char kReceiveConnectionFailed2[];
      static const char *pReceiveDeactiveGprsDpdOk;
      static const char *pClose;
      static const char *pClosed;
      static const char *pConnectionFailed1;
      static const char *pConnectionFailed2;
      static const char *pContentLength;
      static const char *pHeaderGetSend;
      static int siContentLength;
      void static DisconnectToHost ();
      void static DisconnectAfterError ();
      void static SendDataByGet ();
    #endif

    #ifdef I_NEED_SMS_FUNCTIONS
      static const char kSendSmsTextMode[];
      static const char kSendSmsSendConfig[];
      static const char kSendSmsSendText[];
      static const char kSendSmsReadMessageId[];
      static const char kSendSmsReadMessageStatus[];
      static const char kSendSmsDeleteMessageId[];
      static const char kSendSmsDeleteMessageStatus[];
      static const char kSendSmsAdvancedMode[];
      static const char kReceiveCmti[];
      static const char kReceiveOkEndMessage[];
      static const char kReceiveCmgl[];
      static const char kReceiveCmgr[];
      static const char kReceiveCmt[];
      static const char *pOkEndMessage;
      static const char *pCmti;
      static const char *pCmgl;
      static const char *pCmgr;
      static const char *pReceiveCmt;
      void static SmsSend ();
      void static SmsReadById ();
      void static SmsReadByStatus ();
      void static SmsReadAndDeleteById ();
      void static SmsDeleteById ();
      void static SmsDeleteByStatus ();
    #endif

    //#if defined I_NEED_CALL_FUNCTIONS || defined I_NEED_USE_INTERNET_FUNCTIONS
      static const char kReceiveSmsTextRedyToSend[];
      char static DayOfWeek (char *apchDay );
    //#endif

    #ifdef I_NEED_CALL_FUNCTIONS
      static const char kSendDialNumberInVoiceMode[];
      static const char kSendHangUpInVoiceMode[];
      static const char kSendAnsweringInVoiceMode[];
      static const char kReceiveNoCarrier[];
      static const char kReceiveNoDialTone1[];
      static const char kReceiveNoDialTone2[];
      static const char kReceiveNoAnswer[];
      static const char kReceiveBusy[];
      static const char kReceiveRingString[];
      static const char kReceiveCarrierNumber[];
      static const char kSendCarrierNumber[];
      static const char *pRingString;
      static const char *pNoCarrier;
      static const char *pError;
      static const char *pNoDialTone1;
      static const char *pNoDialTone2;
      static const char *pNoAnswer;
      static const char *pBusy;
      static const char *pCarrierNumber;
      void static CallDial ();
      void static CallHangUp ();
      void static CallAnswering ();
      void static CallGetNumber ();
    #endif

    #ifdef I_NEED_ROOT_FUNCTIONS
      static const char kReceiveRootNumberEnable[];
      static const char *pReceiveRootNumberEnable;

      static const char kReceiveRootNumberDisable[];
      static const char *pReceiveRootNumberDisable;

      static const char kReceiveRootNumberAddPhoneBook[];
      static const char *pReceiveRootNumberAddPhoneBook;

      static const char kReceiveRootNumberDelPhoneBook[];
      static const char *pReceiveRootNumberDelPhoneBook;

      static const char kRootName[];
      static const char *pRootName;

      static void SetRootPhoneBook ();
      static void ClearRootPhoneBook ();
    #endif

    #ifdef I_NEED_GEO_FUNCTIONS
      static const char kSendEnginneringModeOn[];
      static const char kSendEnginneringGet[];
      static const char kReceiveEnginneringModeData[];
      static const char *pReceiveEnginneringModeData;
      static void GetEnginneringData ();
    #endif

    #ifdef I_NEED_QUALITY_FUNCTIONS
      static const char kReceiveSignalQuality[];
      static const char kSendSignalQuality[];
      static const char *pSignalQuality;
      void static SignalQuality ();
    #endif

    #ifdef I_NEED_PHONEBOOK_FUNCTIONS
      static const char kReceivePhoneBookFind[];
      static const char kSendPhoneBookClearId[];
      static const char kSendPhoneBookWriteId[];
      static const char kSendPhoneBookWrite[];
      static const char kSendPhoneBookFind[];

      static const char *pReceivePhoneBookFind;

      void static PhoneBookSet ();
      void static PhoneBookIdSet ();
      void static PhoneBookClearId ();
      void static PhoneBookFind ();
      void static PhoneBookFindId ();
    #endif

    static StatusModem StatusEvent;
    static ExternalDataModem DataSendEvent;
    static ExternalDataModem DataReceivedEvent;

    static eStep EnumStep;
    static eEvent EnumEvent;

    static bool gblInternetConnect;

    static char *pchSmsNew;
    static char *pchSmsNewOriginal;
    static char *pchCmtPhone;
    static char *pchCmtPhoneOriginal;
    static char *pchCmtDay;
    static char *pchCmtDayOriginal;
    static char *pchCmtTime;
    static char *pchCmtTimeOriginal;
    static char *pchCmtMessage;
    static char *pchCmtMessageOriginal;

    static char *pchTmpValue;
    static char **ppchTmpAddr;

    static char *pDataList[];//20

    static const char *pOriginal;
    static const char *pCallReady;

    static const char *pDataTxToModem[];//13
    static const char *pDataRxToModem[];//13

    static int siDataListLine;
    static int siDataTxPointerLine;
    static int siDataRxPointerLine;
    static int siGenericCounter;

    static char schFlags;

    static const char kSendEchoOff[];
    static const char kSendEchoOn[];
    static const char kReceiveCallReady[];
    static const char kReceiveOk[];
    static const char kReceiveError[];

    AtModem();
    void static Init ();
    bool static __GetTest( const char **apcchPointer, const char *apcchPointerStart, char achRx, Event::eEvent e );
    void static Get ( char achChar );
    void static FlagSet ( char achFlag );
    void static FlagClear ( char achFlag );
    bool static FlagTest ( char achFlag );
    void static ConstCharToChar ( const char *p1, char *p2 );
    void static ConstCharToChar ( char *p1, char *p2 );
    void static ResetPointers ();
    void static OnEvent ( eEvent aenEvent );
    void static EchoOn ();
    void static EchoOff ();
    void static StateMachine ();
    void static StateMachineRun ();
    void static StateMachineResetAndRun ();
    void static PontSecuryCopy ( char **pchOriginal, char **pchNew );
    void static PointReturnAfterSecuryCopy ();
    void static Checker ( const char *apcchPointer, char *apchRx, Event::eEvent e );
};

#endif // ATMODEM_H
