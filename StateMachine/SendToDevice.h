#ifndef SENDTODEVICE_H
#define SENDTODEVICE_H

#define SEND_TO_DEVICE_FLAG_RUNING 0
#define SEND_TO_DEVICE_FLAG_NEXT_STEP 1
#define SEND_TO_DEVICE_FLAG_WAITING 2
#define SEND_TO_DEVICE_FLAG_CHECK_END 3
#define SEND_TO_DEVICE_FLAG_PROCCESS_END 4


#include "stackenum.h"
#include "../typesKemper.h"

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
class SendToDevice
{
  public:
    SendToDevice( typeStackStepsSize stackStepsSizeAUCh, typeStackDataSize stackDataSizeAUCh );
    void setSendFunction ( PT_VOID_CH functPointerAPFn );
    void setComplemetaryGetFunction ( PT_VOID_CH functPointerAPFn );
    void onIncomingData ( typeDataToExchange achChar );
    bool testChar ( typeDataToExchange **apcchPointer, typeDataToExchange *apcchPointerStart, typeDataToMountBeforeExchange achRx, typeTestEvent e );
    void clear ();
    void addReceiveData ( typeStackStepsSize addressAUCh, typeDataToExchange *dataACSChP );
    void addTransmitData ( typeStackStepsSize addressAUCh, typeDataToExchange *dataACSChP );
    void addPointer ( typeStackDataSize addressAUCh, typeDataToMountBeforeExchange *dataASCh );
    void infinityLoop ();
    void run ();
    ~SendToDevice();

  private:
    void flagSet ( char flagACh );
    void flagClear ( char flagACh );
    bool flagTest ( char flagACh );
    void send ();

    PT_VOID_CH sendCPFnc;
    PT_VOID_CH makeComplementaryGetCPFnc;

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

template class SendToDevice<const char, char, unsigned char, unsigned char, Event::eEvent>;

#endif // SENDTODEVICE_H
