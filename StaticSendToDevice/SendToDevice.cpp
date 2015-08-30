#include "SendToDevice.h"



template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
unsigned int SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::bufferLengthCUInt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
PT_VOID_VOID SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc;


template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
PT_VOID_VOID SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onEndCPFnc;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
PT_VOID_CH SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeDataToMountBeforeExchange *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeDataToMountBeforeExchange *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
char SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagsCCh;


template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
PT_VOID_VOID *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::functionToExecuteCPFnc;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeDataToMountBeforeExchange **SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeDataToExchange **SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeDataToExchange **SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt;


template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeStackStepsSize SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeStackDataSize SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackDataSizeCTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeStackStepsSize SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackFunctionsSizeCTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeStackDataSize SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeStackStepsSize SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeStackStepsSize SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt;














template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::SendToDevice()
{

}
template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::init( typeStackStepsSize stackStepsSizeAUCh, typeStackDataSize stackDataSizeAUCh, typeStackStepsSize stackFunctionsSizeAUCh )
{
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt = new typeDataToMountBeforeExchange*[ stackDataSizeAUCh ];
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt = new typeDataToExchange*[ stackStepsSizeAUCh ];
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt = new typeDataToExchange*[ stackStepsSizeAUCh ];
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::functionToExecuteCPFnc = new PT_VOID_VOID[ stackFunctionsSizeAUCh ];

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt = stackStepsSizeAUCh;
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackDataSizeCTplt  = stackDataSizeAUCh;
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackFunctionsSizeCTplt = stackFunctionsSizeAUCh;

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt = 0;
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt = 0;

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt   = 0;

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onEndCPFnc = 0;
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc = 0;
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc  = 0;

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = 0;
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal = 0;
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::bufferLengthCUInt = 0;

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::clear()
{
  for ( unsigned char i = 0; i != SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt; i += 1 )
  {
    SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ i ] = 0;
    SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ i ] = 0;
  }

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData  = SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal;
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::bufferLengthCUInt = 0;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::addFunctionData ( typeStackStepsSize addressATplt, PT_VOID_VOID functionAddressAPTplt )
{
  if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackFunctionsSizeCTplt <= addressATplt )
  {
    return;
  }

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::functionToExecuteCPFnc[ addressATplt ] = functionAddressAPTplt;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::addReceiveData ( typeStackStepsSize addressATplt, typeDataToExchange *dataAddressAPTplt )
{
  if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt <= addressATplt )
  {
    return;
  }

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ addressATplt ] = dataAddressAPTplt;

  if ( addressATplt + 1 <= SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt )
  {
    SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ addressATplt + 1 ] = 0;
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::addTransmitData ( typeStackStepsSize addressATplt, typeDataToExchange *dataAddressAPTplt )
{
  if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt <= addressATplt )
  {
    return;
  }

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ addressATplt ] = dataAddressAPTplt;

  if ( addressATplt + 1 <= SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt )
  {
    SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ addressATplt + 1 ] = 0;
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::addPointer ( typeStackDataSize addressATplt, typeDataToMountBeforeExchange *dataAddressAPTplt )
{
  if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackDataSizeCTplt <= addressATplt )
  {
    return;
  }

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ addressATplt ] = dataAddressAPTplt;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setOnBufferFullFunction ( PT_VOID_VOID functPointerAPFn )
{
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc = functPointerAPFn;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setSendFunction ( PT_VOID_CH functPointerAPFn )
{
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc = functPointerAPFn;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setSendToDataPointer ( typeDataToMountBeforeExchange *toDataATplt )
{
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData         = toDataATplt;
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal = toDataATplt;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setSendToDataPointer ( typeDataToMountBeforeExchange *toDataATplt, unsigned int lengthAUInt )
{
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData         = toDataATplt;
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal = toDataATplt;

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::bufferLengthCUInt         = lengthAUInt;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setOnEndFunction (PT_VOID_VOID functPointerAPFn )
{
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onEndCPFnc = functPointerAPFn;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::destructor()
{
  delete[] SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt;
  delete[] SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt;
  delete[] SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt;
  delete[] SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::functionToExecuteCPFnc;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::send ()
{
  char dataToSendLCh;
  typeStackDataSize dataPointerCounterTplt = 0;
  typeDataToExchange *dataPointerTplt = 0;
  typeDataToMountBeforeExchange *userDataLPCh = '\0';
  unsigned int contadorLUInt = 0;
  unsigned int contadorPointerLUInt = 0;

  while ( true )
  {
    dataToSendLCh = *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ];

    if ( dataToSendLCh == '\0' )
    {
      SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ++;

      if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] == '\0' )
      {
        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_RUNING );
        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_PROCCESS_END );
        return;
      }

      else
      {
        if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] != '\0' )
        {
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_WAITING );
        }

        /*
        original
        if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] == '\0' )
        {
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_PROCCESS_END );
        }
        else
        {
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_WAITING );
        }
        */
        return;
      }
    }

    else
    {
      SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] ++;
    }

    if ( ( dataToSendLCh == '{' ) && ( *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] == 'p' ) && ( *( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 1 ) == 't' ) )
    {
      SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] += 3;
      userDataLPCh = SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt++ ];
    }

    else if ( ( dataToSendLCh == '{' ) && ( *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] == 'b' ) && ( *( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 1 ) == 'y' ) && ( *( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 2 ) == 'e' ) )
    {
      SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] += 4;
      dataToSendLCh = char( 0x1A );
    }

    //{ad:nnn}
    else if ( ( dataToSendLCh == '{' ) && ( *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] == 'a' ) && ( *( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 1 ) == 'd' ) && ( *( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 2 ) == ':' ) )
    {
      dataPointerCounterTplt = 0;
      contadorPointerLUInt = 0;
      dataPointerTplt  = SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 3;
      do
      {
        if ( ( *dataPointerTplt >= '0' ) && ( *dataPointerTplt <= '9' ) )
        {
          dataPointerCounterTplt *= 10;
          dataPointerCounterTplt += ( *dataPointerTplt - 0x30 );
          dataPointerTplt += 1;
          contadorPointerLUInt += 1;
        }
        else if ( *dataPointerTplt == '}' )
        {
          userDataLPCh = SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ dataPointerCounterTplt ];
          break;
        }
      }
      while ( true );

      SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] += ( contadorPointerLUInt + 4 );
    }

    //{fn:nnn}
    else if ( ( dataToSendLCh == '{' ) && ( *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] == 'f' ) && ( *( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 1 ) == 'n' ) && ( *( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 2 ) == ':' ) )
    {
      dataPointerCounterTplt = 0;
      contadorPointerLUInt = 0;
      dataPointerTplt  = SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 3;
      do
      {
        if ( ( *dataPointerTplt >= '0' ) && ( *dataPointerTplt <= '9' ) )
        {
          dataPointerCounterTplt *= 10;
          dataPointerCounterTplt += ( *dataPointerTplt - 0x30 );
          dataPointerTplt += 1;
          contadorPointerLUInt += 1;
        }
        else if ( *dataPointerTplt == '}' )
        {
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::functionToExecuteCPFnc[ dataPointerCounterTplt ] ();
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] += ( contadorPointerLUInt + 4 );
          return;
        }
      }
      while ( true );
    }

    if ( userDataLPCh != 0 )
    {
      while ( *userDataLPCh != 0 )
      {
        if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc != 0 )
        {
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc ( *userDataLPCh );
        }

        if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData != 0 )
        {
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = *userDataLPCh;
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData += 1;
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = 0;

          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );

          if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc != 0 )
          {
            contadorLUInt += 1;

            if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::bufferLengthCUInt == contadorLUInt )
            {
              contadorLUInt = 0;
              SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );
              SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc();

              SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal;
            }
          }
        }
        userDataLPCh ++;
      }
      userDataLPCh = '\0';
    }

    else
    {
      if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc != 0 )
      {
        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc ( dataToSendLCh );
      }

      if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData != 0 )
      {
        *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = dataToSendLCh;
        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData += 1;
        *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = 0;

        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );

        if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc != 0 )
        {
          contadorLUInt += 1;

          if ( ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::bufferLengthCUInt == contadorLUInt ) || ( dataToSendLCh == 0 ) )
          {
            contadorLUInt = 0;
            SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );
            SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc();

            SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal;
          }
        }
      }
    }
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onIncomingData ( typeDataToExchange inDataATplt )
{
  // Maquina de estados - inicio ->
  if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] != '\0' )
  {
    if ( *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] == inDataATplt )
    {
      SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] ++;
      if ( *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] == '\0' )
      {
        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ++;
        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_WAITING );

        if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] == '\0' )
        {
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_PROCCESS_END );
        }
      }
    }
    else
    {
      SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] = &SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ][ 0 ];
      //SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::EnumEvent = Event::EndLine;
      //SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::OnEvent ( Event::EndLine );
      //StackEnum::Add( Event::EndLine );
    }
  }
  else
  {
    SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_PROCCESS_END );
  }
  // Maquina de estados <- fim
}

/**
 * @brief SendToDevice::testPointer
 * {time} - Captura data/hora, formato: [0-9]{1,}[:/][0-9]{1,}[0-9]{1,}[:/]
 * {inum} - Ignora número, formato: [^0-9]{1,}
 * {snum} - Captura número, formato: [0-9+-]{1,}
 * {num}  - Captura número, formato: [0-9]{1,}
 * {hex}  - Captura número, formato: [0-9a-fA-F]{1,}
 * {str}  - Captura texto, formato: [0-9a-z(sp)]{1,}
 * {istr} - Ignora texto, formato: [^0-9a-z(sp)]{1,}
 * {all}  - Captura tudo, formato: [^\r\n\0]
 * @param apcchPointer
 * @param apcchPointerStart
 * @param inDataATplt
 * @param e
 * @return
 */
template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
char SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::testPointer ( typeDataToExchange **apcchPointer, typeDataToExchange *apcchPointerStart, typeDataToMountBeforeExchange inDataATplt )
{
  char returnLCh = 0;
  restart_process:
  if ( **apcchPointer == ( typeDataToExchange )'{' )
  {
    // type: time
    if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'t' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'i' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'m' ) && ( *( ( *apcchPointer ) + 4 ) == ( typeDataToExchange )'e' ) )
    {
      if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] != 0 )
      {
        if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( inDataATplt == ( typeDataToExchange )':' ) || ( inDataATplt == ( typeDataToExchange )'/' ) )
        {
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = inDataATplt;
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] ++;
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = 0;
          return returnLCh;
        }

        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ++;
      }

      else
      {
        returnLCh = ( char ) -1;
        //StackEnum::Add( Event::PTimeError );
        goto reset_pointers;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 6;
    }

    // type: inum
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'i' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'n' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'u' ) && ( *( ( *apcchPointer ) + 4 ) == ( typeDataToExchange )'m' ) )
    {
      if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( inDataATplt == ( typeDataToExchange )'+' ) || ( inDataATplt == ( typeDataToExchange )'-' ) )
      {
        return returnLCh;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 6;
    }

    // type: snum
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'s' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'n' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'u' ) && ( *( ( *apcchPointer ) + 4 ) == ( typeDataToExchange )'m' ) )
    {
      if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] != '\0' )
      {
        if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( inDataATplt == ( typeDataToExchange )'+' ) || ( inDataATplt == ( typeDataToExchange )'-' ) )
        {
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = inDataATplt;
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] ++;
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = 0;
          return returnLCh;
        }

        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ++;
      }

      else
      {
        returnLCh = ( char ) -2;
        //StackEnum::Add( Event::PSNumError );
        goto reset_pointers;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 6;
    }

    // type: hex
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'h' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'e' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'x' ) )
    {
      if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] != 0 )
      {
        if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'a' ) && ( inDataATplt <= ( typeDataToExchange )'f' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'A' ) && ( inDataATplt <= ( typeDataToExchange )'F' ) ) )
        {
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = inDataATplt;
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] ++;
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = 0;
          return returnLCh;
        }

        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ++;
      }

      else
      {
        returnLCh = ( char ) -3;
        //StackEnum::Add( Event::PSHexError );
        goto reset_pointers;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 5;
    }

    // type: num
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'n' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'u' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'m' ) )
    {
      if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] != 0 )
      {
        if ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) )
        {
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = inDataATplt;
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] ++;
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = 0;
          return returnLCh;
        }

        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ++;
      }

      else
      {
        returnLCh = ( char ) -4;
        //StackEnum::Add( Event::PNumError );
        goto reset_pointers;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 5;
    }

    // type: str
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'s' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'t' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'r' ) )
    {
      if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] != 0 )
      {
        if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'A' ) && ( inDataATplt <= ( typeDataToExchange )'Z' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'a' ) && ( inDataATplt <= ( typeDataToExchange )'z' ) ) || ( inDataATplt == ( typeDataToExchange )' ' ) )
        {
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = inDataATplt;
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] ++;
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = 0;
          return returnLCh;
        }

        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ++;
      }

      else
      {
        returnLCh = ( char ) -5;
        //StackEnum::Add( Event::PStrError );
        goto reset_pointers;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 5;
    }

    // type: inum
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'i' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'s' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'t' ) && ( *( ( *apcchPointer ) + 4 ) == ( typeDataToExchange )'r' ) )
    {
      if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'A' ) && ( inDataATplt <= ( typeDataToExchange )'Z' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'a' ) && ( inDataATplt <= ( typeDataToExchange )'z' ) ) || ( inDataATplt == ( typeDataToExchange )' ' ) )
      {
        return returnLCh;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 6;
    }

    // type: all
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'a' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'l' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'l' ) )
    {
      if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] != 0 )
      {
        if ( ( inDataATplt != ( typeDataToExchange )'\r' ) && ( inDataATplt != ( typeDataToExchange )'\n' ) && ( inDataATplt != 0 ) )
        {
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = inDataATplt;
          SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] ++;
          *SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = 0;
          return returnLCh;
        }

        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ++;
      }

      else
      {
        returnLCh = ( char ) -6;
        //StackEnum::Add( Event::PAllError );
        goto reset_pointers;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 5;
    }
  }

  if ( **apcchPointer == ( typeDataToExchange )'{' )
  {
    goto restart_process;
  }

  else if ( **apcchPointer == 0 )
  {
    ( *apcchPointer ) = apcchPointerStart;
    SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_CHECK_END );
    //qDebug() << "SEND_TO_DEVICE_FLAG_CHECK_END";
    returnLCh = ( char ) 1;
    //StackEnum::Add( e );
    goto reset_pointers;
  }

  else if ( ( **apcchPointer == inDataATplt ) || ( **apcchPointer == 0 ) )
  {
    ( *apcchPointer ) ++;

    if ( **apcchPointer == 0 )
    {
      ( *apcchPointer ) = apcchPointerStart;
      SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_CHECK_END );
      //qDebug() << "SEND_TO_DEVICE_FLAG_CHECK_END";
      returnLCh = ( char ) 1;
      //StackEnum::Add( e );
      goto reset_pointers;
    }

    return returnLCh;
  }

  reset_pointers:
    ( *apcchPointer ) = apcchPointerStart;
    return returnLCh;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::run ()
{
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt = 0;

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt = 0;
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt = 0;

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_WAITING );
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_NEXT_STEP );
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_EVENT_SEND );

  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_RUNING );
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::infinityLoop ()
{
  if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagTest( SEND_TO_DEVICE_FLAG_RUNING ) == true )
  {
    if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagTest( SEND_TO_DEVICE_FLAG_WAITING ) == false )
    {
      SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::send ();
    }
  }

  else
  {
    if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagTest( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND ) == true )
    {
      SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );
      if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc != 0 )
      {
        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc();
      }
    }

    if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagTest( SEND_TO_DEVICE_FLAG_EVENT_SEND ) == false )
    {
      SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_EVENT_SEND );
      //qDebug() << "On end function run";

      if ( SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onEndCPFnc != 0 )
      {
        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal;
        SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onEndCPFnc ();
      }
    }
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet ( char flagACh )
{
  char flagLCh = 1 << flagACh;
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagsCCh |= flagLCh;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear ( char flagACh )
{
  char flagLCh = 1 << flagACh;
  flagLCh = ~flagLCh;
  SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagsCCh &= flagLCh;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
bool SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagTest ( char flagACh )
{
  char flagLCh = 1 << flagACh;
  flagLCh = SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagsCCh & flagLCh;

  if ( flagLCh == 0 )
  {
    return false;
  }

  return true;
}
