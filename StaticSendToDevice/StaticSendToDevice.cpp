#include "StaticSendToDevice.h"



template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
unsigned int StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::bufferLengthCUInt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
PT_VOID_VOID StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc;


template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
PT_VOID_VOID StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onEndCPFnc;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
PT_VOID_CH StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeDataToMountBeforeExchange *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeDataToMountBeforeExchange *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
char StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagsCCh;


template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
PT_VOID_VOID *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::functionToExecuteCPFnc;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeDataToMountBeforeExchange **StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeDataToExchange **StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeDataToExchange **StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt;


template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeStackStepsSize StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeStackDataSize StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackDataSizeCTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeStackStepsSize StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackFunctionsSizeCTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeStackDataSize StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeStackStepsSize StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt;

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
typeStackStepsSize StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt;














template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::StaticSendToDevice()
{

}
template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::init( typeStackStepsSize stackStepsSizeAUCh, typeStackDataSize stackDataSizeAUCh, typeStackStepsSize stackFunctionsSizeAUCh )
{
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt = new typeDataToMountBeforeExchange*[ stackDataSizeAUCh ];
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt = new typeDataToExchange*[ stackStepsSizeAUCh ];
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt = new typeDataToExchange*[ stackStepsSizeAUCh ];
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::functionToExecuteCPFnc = new PT_VOID_VOID[ stackFunctionsSizeAUCh ];

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt = stackStepsSizeAUCh;
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackDataSizeCTplt  = stackDataSizeAUCh;
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackFunctionsSizeCTplt = stackFunctionsSizeAUCh;

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt = 0;
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt = 0;

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt   = 0;

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onEndCPFnc = 0;
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc = 0;
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc  = 0;

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = 0;
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal = 0;
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::bufferLengthCUInt = 0;

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::clear()
{
  for ( unsigned char i = 0; i != StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt; i += 1 )
  {
    StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ i ] = 0;
    StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ i ] = 0;
  }

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData  = StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal;
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::bufferLengthCUInt = 0;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::addFunctionData ( typeStackStepsSize addressATplt, PT_VOID_VOID functionAddressAPTplt )
{
  if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackFunctionsSizeCTplt <= addressATplt )
  {
    return;
  }

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::functionToExecuteCPFnc[ addressATplt ] = functionAddressAPTplt;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::addReceiveData ( typeStackStepsSize addressATplt, typeDataToExchange *dataAddressAPTplt )
{
  if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt <= addressATplt )
  {
    return;
  }

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ addressATplt ] = dataAddressAPTplt;

  if ( addressATplt + 1 <= StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt )
  {
    StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ addressATplt + 1 ] = 0;
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::addTransmitData ( typeStackStepsSize addressATplt, typeDataToExchange *dataAddressAPTplt )
{
  if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt <= addressATplt )
  {
    return;
  }

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ addressATplt ] = dataAddressAPTplt;

  if ( addressATplt + 1 <= StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackStepsSizeCTplt )
  {
    StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ addressATplt + 1 ] = 0;
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::addPointer ( typeStackDataSize addressATplt, typeDataToMountBeforeExchange *dataAddressAPTplt )
{
  if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::stackDataSizeCTplt <= addressATplt )
  {
    return;
  }

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ addressATplt ] = dataAddressAPTplt;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setOnBufferFullFunction ( PT_VOID_VOID functPointerAPFn )
{
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc = functPointerAPFn;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setSendFunction ( PT_VOID_CH functPointerAPFn )
{
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc = functPointerAPFn;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setSendToDataPointer ( typeDataToMountBeforeExchange *toDataATplt )
{
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData         = toDataATplt;
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal = toDataATplt;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setSendToDataPointer ( typeDataToMountBeforeExchange *toDataATplt, unsigned int lengthAUInt )
{
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData         = toDataATplt;
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal = toDataATplt;

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::bufferLengthCUInt         = lengthAUInt;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setOnEndFunction (PT_VOID_VOID functPointerAPFn )
{
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onEndCPFnc = functPointerAPFn;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::destructor()
{
  delete[] StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt;
  delete[] StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt;
  delete[] StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt;
  delete[] StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::functionToExecuteCPFnc;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::send ()
{
  char dataToSendLCh;
  typeStackDataSize dataPointerCounterTplt = 0;
  typeDataToExchange *dataPointerTplt = 0;
  typeDataToMountBeforeExchange *userDataLPCh = '\0';
  unsigned int contadorLUInt = 0;
  unsigned int contadorPointerLUInt = 0;

  while ( true )
  {
    dataToSendLCh = *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ];

    if ( dataToSendLCh == '\0' )
    {
      StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ++;

      if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] == '\0' )
      {
        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_RUNING );
        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_PROCCESS_END );
        return;
      }

      else
      {
        if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] != '\0' )
        {
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_WAITING );
        }

        /*
        original
        if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] == '\0' )
        {
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_PROCCESS_END );
        }
        else
        {
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_WAITING );
        }
        */
        return;
      }
    }

    else
    {
      StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] ++;
    }

    if ( ( dataToSendLCh == '{' ) && ( *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] == 'p' ) && ( *( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 1 ) == 't' ) )
    {
      StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] += 3;
      userDataLPCh = StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt++ ];
    }

    else if ( ( dataToSendLCh == '{' ) && ( *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] == 'b' ) && ( *( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 1 ) == 'y' ) && ( *( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 2 ) == 'e' ) )
    {
      StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] += 4;
      dataToSendLCh = char( 0x1A );
    }

    //{ad:nnn}
    else if ( ( dataToSendLCh == '{' ) && ( *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] == 'a' ) && ( *( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 1 ) == 'd' ) && ( *( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 2 ) == ':' ) )
    {
      dataPointerCounterTplt = 0;
      contadorPointerLUInt = 0;
      dataPointerTplt  = StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 3;
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
          userDataLPCh = StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ dataPointerCounterTplt ];
          break;
        }
      }
      while ( true );

      StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] += ( contadorPointerLUInt + 4 );
    }

    //{fn:nnn}
    else if ( ( dataToSendLCh == '{' ) && ( *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] == 'f' ) && ( *( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 1 ) == 'n' ) && ( *( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 2 ) == ':' ) )
    {
      dataPointerCounterTplt = 0;
      contadorPointerLUInt = 0;
      dataPointerTplt  = StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] + 3;
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
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::functionToExecuteCPFnc[ dataPointerCounterTplt ] ();
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt ] += ( contadorPointerLUInt + 4 );
          return;
        }
      }
      while ( true );
    }

    if ( userDataLPCh != 0 )
    {
      while ( *userDataLPCh != 0 )
      {
        if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc != 0 )
        {
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc ( *userDataLPCh );
        }

        if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData != 0 )
        {
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = *userDataLPCh;
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData += 1;
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = 0;

          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );

          if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc != 0 )
          {
            contadorLUInt += 1;

            if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::bufferLengthCUInt == contadorLUInt )
            {
              contadorLUInt = 0;
              StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );
              StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc();

              StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal;
            }
          }
        }
        userDataLPCh ++;
      }
      userDataLPCh = '\0';
    }

    else
    {
      if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc != 0 )
      {
        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendCPFnc ( dataToSendLCh );
      }

      if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData != 0 )
      {
        *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = dataToSendLCh;
        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData += 1;
        *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = 0;

        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );

        if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc != 0 )
        {
          contadorLUInt += 1;

          if ( ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::bufferLengthCUInt == contadorLUInt ) || ( dataToSendLCh == 0 ) )
          {
            contadorLUInt = 0;
            StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );
            StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc();

            StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal;
          }
        }
      }
    }
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onIncomingData ( typeDataToExchange inDataATplt )
{
  // Maquina de estados - inicio ->
  if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] != '\0' )
  {
    if ( *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] == inDataATplt )
    {
      StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] ++;
      if ( *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] == '\0' )
      {
        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ++;
        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_WAITING );

        if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] == '\0' )
        {
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_PROCCESS_END );
        }
      }
    }
    else
    {
      StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ] = &StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceiveCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt ][ 0 ];
      //StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::EnumEvent = Event::EndLine;
      //StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::OnEvent ( Event::EndLine );
      //StackEnum::Add( Event::EndLine );
    }
  }
  else
  {
    StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_PROCCESS_END );
  }
  // Maquina de estados <- fim
}

/**
 * @brief StaticSendToDevice::testPointer
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
char StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::testPointer ( typeDataToExchange **apcchPointer, typeDataToExchange *apcchPointerStart, typeDataToMountBeforeExchange inDataATplt )
{
  char returnLCh = 0;
  restart_process:
  if ( **apcchPointer == ( typeDataToExchange )'{' )
  {
    // type: time
    if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'t' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'i' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'m' ) && ( *( ( *apcchPointer ) + 4 ) == ( typeDataToExchange )'e' ) )
    {
      if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] != 0 )
      {
        if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( inDataATplt == ( typeDataToExchange )':' ) || ( inDataATplt == ( typeDataToExchange )'/' ) )
        {
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = inDataATplt;
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] ++;
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = 0;
          return returnLCh;
        }

        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ++;
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
      if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] != '\0' )
      {
        if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( inDataATplt == ( typeDataToExchange )'+' ) || ( inDataATplt == ( typeDataToExchange )'-' ) )
        {
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = inDataATplt;
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] ++;
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = 0;
          return returnLCh;
        }

        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ++;
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
      if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] != 0 )
      {
        if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'a' ) && ( inDataATplt <= ( typeDataToExchange )'f' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'A' ) && ( inDataATplt <= ( typeDataToExchange )'F' ) ) )
        {
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = inDataATplt;
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] ++;
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = 0;
          return returnLCh;
        }

        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ++;
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
      if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] != 0 )
      {
        if ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) )
        {
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = inDataATplt;
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] ++;
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = 0;
          return returnLCh;
        }

        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ++;
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
      if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] != 0 )
      {
        if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'A' ) && ( inDataATplt <= ( typeDataToExchange )'Z' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'a' ) && ( inDataATplt <= ( typeDataToExchange )'z' ) ) || ( inDataATplt == ( typeDataToExchange )' ' ) )
        {
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = inDataATplt;
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] ++;
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = 0;
          return returnLCh;
        }

        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ++;
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
      if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] != 0 )
      {
        if ( ( inDataATplt != ( typeDataToExchange )'\r' ) && ( inDataATplt != ( typeDataToExchange )'\n' ) && ( inDataATplt != 0 ) )
        {
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = inDataATplt;
          StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] ++;
          *StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataToMountCPTplt[ StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ] = 0;
          return returnLCh;
        }

        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt ++;
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
    StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_CHECK_END );
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
      StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_CHECK_END );
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
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::run ()
{
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataListLineCTplt = 0;

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataTransmitPointerLineCTplt = 0;
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::dataReceivePointerLineCTplt = 0;

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_WAITING );
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_NEXT_STEP );
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_EVENT_SEND );

  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_RUNING );
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::infinityLoop ()
{
  if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagTest( SEND_TO_DEVICE_FLAG_RUNING ) == true )
  {
    if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagTest( SEND_TO_DEVICE_FLAG_WAITING ) == false )
    {
      StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::send ();
    }
  }

  else
  {
    if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagTest( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND ) == true )
    {
      StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );
      if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc != 0 )
      {
        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onBufferFullCPFnc();
      }
    }

    if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagTest( SEND_TO_DEVICE_FLAG_EVENT_SEND ) == false )
    {
      StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet( SEND_TO_DEVICE_FLAG_EVENT_SEND );
      //qDebug() << "On end function run";

      if ( StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onEndCPFnc != 0 )
      {
        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToData = StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::sendToDataOriginal;
        StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::onEndCPFnc ();
      }
    }
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet ( char flagACh )
{
  char flagLCh = 1 << flagACh;
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagsCCh |= flagLCh;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear ( char flagACh )
{
  char flagLCh = 1 << flagACh;
  flagLCh = ~flagLCh;
  StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagsCCh &= flagLCh;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
bool StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagTest ( char flagACh )
{
  char flagLCh = 1 << flagACh;
  flagLCh = StaticSendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagsCCh & flagLCh;

  if ( flagLCh == 0 )
  {
    return false;
  }

  return true;
}
