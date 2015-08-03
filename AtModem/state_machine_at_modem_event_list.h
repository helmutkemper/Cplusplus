#ifndef STATE_MACHINE_AT_MODEM_EVENT_LIST_H
#define STATE_MACHINE_AT_MODEM_EVENT_LIST_H

namespace Event
{
  enum eEvent
  {
    None,
    PTimeError,
    PNumError,
    PSNumError,
    PSHexError,
    PStrError,
    PAllError,
    PSmsError,
    PCmtMsgError,
    PCmtTimeError,
    PCmtDayError,
    PCmtPhoneError,

    #ifdef I_NEED_ROOT_FUNCTIONS
    RootEnable,
    RootDisable,
    RootAddData,
    RootDelData,
    #endif

    #ifdef I_NEED_USE_INTERNET_FUNCTIONS
      InternetReadStart,
      InternetReadEnd,
      Close,
      ConnectionFailed,
      InternetConnect,
      InternetDisconnect,
    #endif
    #ifdef I_NEED_GEO_FUNCTIONS
      EnginneringData,
      EnginneringDataToGeo,
    #endif
    #ifdef I_NEED_PHONEBOOK_FUNCTIONS
      PhoneBookFind,
    #endif
    EndLine,
    EndProcess,
    CarrierNumberCaptured,
    Ring,
    SMSNew,
    SMSSend,
    SMSReadByStatus,
    SMSRead,
    SMSCompanyRead,
    SMSNumberAvailable,
    SMSDeleted,
    PowerOn,


    SimReady,
    SimPin,
    SimPuk,
    SimPhPin,
    SimPhPuk,
    SimPinNotFound,

    NoCarrier,
    NoDialTone,
    NoAnswer,
    Busy,
    Error,

    CallReady,
    PowerDown,
    SignalQuality,
    RTCRead,

    UserEvent1,
    UserEvent2,
    SetRtc,
    ReceiveRootNumber,
    CommandNormal,
    AddTimer,
    CommandDisabe,
    CommandEnable,
    CommandReset,
    TimerOn,
    TimerOff,
    ReadTimer,
    IntervalSensor,
    UserEvent14,
    UserEvent15,
    UserEvent16,
    UserEvent17,
    UserEvent18,
    UserEvent19,
    UserEvent20
  };
}
using namespace Event;

#endif // STATE_MACHINE_AT_MODEM_EVENT_LIST_H