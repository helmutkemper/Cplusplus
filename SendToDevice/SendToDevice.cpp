#include "SendToDevice.h"

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::SendToDevice( typeStackStepsSize stackStepsSizeAUCh, typeStackDataSize stackDataSizeAUCh, typeStackStepsSize stackFunctionsSizeAUCh )
{
  this->dataToMountCPTplt = new typeDataToMountBeforeExchange*[ stackDataSizeAUCh ];
  this->dataTransmitCPTplt = new typeDataToExchange*[ stackStepsSizeAUCh ];
  this->dataReceiveCPTplt = new typeDataToExchange*[ stackStepsSizeAUCh ];
  this->functionToExecuteCPFnc = new PT_VOID_VOID[ stackFunctionsSizeAUCh ];

  this->stackStepsSizeCTplt = stackStepsSizeAUCh;
  this->stackDataSizeCTplt  = stackDataSizeAUCh;
  this->stackFunctionsSizeCTplt = stackFunctionsSizeAUCh;

  this->dataTransmitPointerLineCTplt = 0;
  this->dataReceivePointerLineCTplt = 0;

  this->dataListLineCTplt   = 0;

  this->onEndCPFnc = 0;
  this->onBufferFullCPFnc = 0;
  this->sendCPFnc  = 0;

  this->sendToData = 0;
  this->sendToDataOriginal = 0;
  this->bufferLengthCUInt = 0;

  this->flagClear( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::clear()
{
  for ( unsigned char i = 0; i != this->stackStepsSizeCTplt; i += 1 )
  {
    this->dataTransmitCPTplt[ i ] = 0;
    this->dataReceiveCPTplt[ i ] = 0;
  }

  this->sendToData  = this->sendToDataOriginal;
  this->bufferLengthCUInt = 0;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::addFunctionData ( typeStackStepsSize addressATplt, PT_VOID_VOID functionAddressAPTplt )
{
  if ( this->stackFunctionsSizeCTplt <= addressATplt )
  {
    return;
  }

  this->functionToExecuteCPFnc[ addressATplt ] = functionAddressAPTplt;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::addReceiveData ( typeStackStepsSize addressATplt, typeDataToExchange *dataAddressAPTplt )
{
  if ( this->stackStepsSizeCTplt <= addressATplt )
  {
    return;
  }

  this->dataReceiveCPTplt[ addressATplt ] = dataAddressAPTplt;

  if ( addressATplt + 1 <= this->stackStepsSizeCTplt )
  {
    this->dataReceiveCPTplt[ addressATplt + 1 ] = 0;
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::addTransmitData ( typeStackStepsSize addressATplt, typeDataToExchange *dataAddressAPTplt )
{
  if ( this->stackStepsSizeCTplt <= addressATplt )
  {
    return;
  }

  this->dataTransmitCPTplt[ addressATplt ] = dataAddressAPTplt;

  if ( addressATplt + 1 <= this->stackStepsSizeCTplt )
  {
    this->dataTransmitCPTplt[ addressATplt + 1 ] = 0;
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::addPointer ( typeStackDataSize addressATplt, typeDataToMountBeforeExchange *dataAddressAPTplt )
{
  if ( this->stackDataSizeCTplt <= addressATplt )
  {
    return;
  }

  this->dataToMountCPTplt[ addressATplt ] = dataAddressAPTplt;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setOnBufferFullFunction ( PT_VOID_VOID functPointerAPFn )
{
  this->onBufferFullCPFnc = functPointerAPFn;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setSendFunction ( PT_VOID_CH functPointerAPFn )
{
  this->sendCPFnc = functPointerAPFn;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setSendToDataPointer ( typeDataToMountBeforeExchange *toDataATplt )
{
  this->sendToData         = toDataATplt;
  this->sendToDataOriginal = toDataATplt;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setSendToDataPointer ( typeDataToMountBeforeExchange *toDataATplt, unsigned int lengthAUInt )
{
  this->sendToData         = toDataATplt;
  this->sendToDataOriginal = toDataATplt;

  this->bufferLengthCUInt         = lengthAUInt;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::setOnEndFunction (PT_VOID_VOID functPointerAPFn )
{
  this->onEndCPFnc = functPointerAPFn;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::~SendToDevice()
{
  delete[] this->dataTransmitCPTplt;
  delete[] this->dataReceiveCPTplt;
  delete[] this->dataToMountCPTplt;
  delete[] this->functionToExecuteCPFnc;
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
    dataToSendLCh = *this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ];

    if ( dataToSendLCh == '\0' )
    {
      this->dataTransmitPointerLineCTplt ++;

      if ( this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] == '\0' )
      {
        this->flagClear( SEND_TO_DEVICE_FLAG_RUNING );
        this->flagSet( SEND_TO_DEVICE_FLAG_PROCCESS_END );
        return;
      }

      else
      {
        if ( this->dataReceiveCPTplt[ this->dataReceivePointerLineCTplt ] != '\0' )
        {
          this->flagSet( SEND_TO_DEVICE_FLAG_WAITING );
        }

        /*
        original
        if ( this->dataReceiveCPTplt[ this->dataReceivePointerLineCTplt ] == '\0' )
        {
          this->flagSet( SEND_TO_DEVICE_FLAG_PROCCESS_END );
        }
        else
        {
          this->flagSet( SEND_TO_DEVICE_FLAG_WAITING );
        }
        */
        return;
      }
    }

    else
    {
      this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] ++;
    }

    if ( ( dataToSendLCh == '{' ) && ( *this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] == 'p' ) && ( *( this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] + 1 ) == 't' ) )
    {
      this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] += 3;
      userDataLPCh = this->dataToMountCPTplt[ this->dataListLineCTplt++ ];
    }

    else if ( ( dataToSendLCh == '{' ) && ( *this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] == 'b' ) && ( *( this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] + 1 ) == 'y' ) && ( *( this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] + 2 ) == 'e' ) )
    {
      this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] += 4;
      dataToSendLCh = char( 0x1A );
    }

    //{ad:nnn}
    else if ( ( dataToSendLCh == '{' ) && ( *this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] == 'a' ) && ( *( this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] + 1 ) == 'd' ) && ( *( this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] + 2 ) == ':' ) )
    {
      dataPointerCounterTplt = 0;
      contadorPointerLUInt = 0;
      dataPointerTplt  = this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] + 3;
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
          userDataLPCh = this->dataToMountCPTplt[ dataPointerCounterTplt ];
          break;
        }
      }
      while ( true );

      this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] += ( contadorPointerLUInt + 4 );
    }

    //{fn:nnn}
    else if ( ( dataToSendLCh == '{' ) && ( *this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] == 'f' ) && ( *( this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] + 1 ) == 'n' ) && ( *( this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] + 2 ) == ':' ) )
    {
      dataPointerCounterTplt = 0;
      contadorPointerLUInt = 0;
      dataPointerTplt  = this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] + 3;
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
          this->functionToExecuteCPFnc[ dataPointerCounterTplt ] ();
          this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] += ( contadorPointerLUInt + 4 );
          return;
        }
      }
      while ( true );
    }

    if ( userDataLPCh != 0 )
    {
      while ( *userDataLPCh != 0 )
      {
        if ( this->sendCPFnc != 0 )
        {
          this->sendCPFnc ( *userDataLPCh );
        }

        if ( this->sendToData != 0 )
        {
          *this->sendToData = *userDataLPCh;
          this->sendToData += 1;
          *this->sendToData = 0;

          this->flagSet( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );

          if ( this->onBufferFullCPFnc != 0 )
          {
            contadorLUInt += 1;

            if ( this->bufferLengthCUInt == contadorLUInt )
            {
              contadorLUInt = 0;
              this->flagClear( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );
              this->onBufferFullCPFnc();

              this->sendToData = this->sendToDataOriginal;
            }
          }
        }
        userDataLPCh ++;
      }
      userDataLPCh = '\0';
    }

    else
    {
      if ( this->sendCPFnc != 0 )
      {
        this->sendCPFnc ( dataToSendLCh );
      }

      if ( this->sendToData != 0 )
      {
        *this->sendToData = dataToSendLCh;
        this->sendToData += 1;
        *this->sendToData = 0;

        this->flagSet( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );

        if ( this->onBufferFullCPFnc != 0 )
        {
          contadorLUInt += 1;

          if ( ( this->bufferLengthCUInt == contadorLUInt ) || ( dataToSendLCh == 0 ) )
          {
            contadorLUInt = 0;
            this->flagClear( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );
            this->onBufferFullCPFnc();

            this->sendToData = this->sendToDataOriginal;
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
  if ( this->dataReceiveCPTplt[ this->dataReceivePointerLineCTplt ] != '\0' )
  {
    if ( *this->dataReceiveCPTplt[ this->dataReceivePointerLineCTplt ] == inDataATplt )
    {
      this->dataReceiveCPTplt[ this->dataReceivePointerLineCTplt ] ++;
      if ( *this->dataReceiveCPTplt[ this->dataReceivePointerLineCTplt ] == '\0' )
      {
        this->dataReceivePointerLineCTplt ++;
        this->flagClear( SEND_TO_DEVICE_FLAG_WAITING );

        if ( this->dataReceiveCPTplt[ this->dataReceivePointerLineCTplt ] == '\0' )
        {
          this->flagSet( SEND_TO_DEVICE_FLAG_PROCCESS_END );
        }
      }
    }
    else
    {
      this->dataReceiveCPTplt[ this->dataReceivePointerLineCTplt ] = &this->dataReceiveCPTplt[ this->dataReceivePointerLineCTplt ][ 0 ];
      //this->EnumEvent = Event::EndLine;
      //this->OnEvent ( Event::EndLine );
      //StackEnum::Add( Event::EndLine );
    }
  }
  else
  {
    this->flagSet( SEND_TO_DEVICE_FLAG_PROCCESS_END );
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

  typeStackStepsSize addressLTplt = 0;
  typeDataToExchange **countPointerLTplt = 4;

  restart_process:


  if ( **apcchPointer == ( typeDataToExchange )'{' )
  {
    // type: pt:NNN
    if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'p' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'t' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )':' ) )
    {
      addressLTplt = 0;
      countPointerLTplt = 4;

      //this->dataToMountCPTplt[ this->dataListLineCTplt ] += 3;
      do
      {
        if ( ( *( apcchPointer + countPointerLTplt ) >= ( typeDataToExchange )'0' ) && ( *( apcchPointer + countPointerLTplt ) <= ( typeDataToExchange )'9' ) )
        {
          addressLTplt *= 10;
          addressLTplt += ( *dataPointerTplt - 0x30 );
          dataPointerTplt += 1;
          contadorPointerLUInt += 1;
        }
        else if ( *dataPointerTplt == '}' )
        {
          userDataLPCh = this->dataToMountCPTplt[ dataPointerCounterTplt ];
          break;
        }
      }
      while ( true );













    }

    // type: time
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'t' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'i' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'m' ) && ( *( ( *apcchPointer ) + 4 ) == ( typeDataToExchange )'e' ) )
    {
      if ( this->dataToMountCPTplt[ this->dataListLineCTplt ] != 0 )
      {
        if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( inDataATplt == ( typeDataToExchange )':' ) || ( inDataATplt == ( typeDataToExchange )'/' ) )
        {
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = inDataATplt;
          this->dataToMountCPTplt[ this->dataListLineCTplt ] ++;
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = 0;
          return returnLCh;
        }

        this->dataListLineCTplt ++;
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
      if ( this->dataToMountCPTplt[ this->dataListLineCTplt ] != '\0' )
      {
        if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( inDataATplt == ( typeDataToExchange )'+' ) || ( inDataATplt == ( typeDataToExchange )'-' ) )
        {
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = inDataATplt;
          this->dataToMountCPTplt[ this->dataListLineCTplt ] ++;
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = 0;
          return returnLCh;
        }

        this->dataListLineCTplt ++;
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
      if ( this->dataToMountCPTplt[ this->dataListLineCTplt ] != 0 )
      {
        if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'a' ) && ( inDataATplt <= ( typeDataToExchange )'f' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'A' ) && ( inDataATplt <= ( typeDataToExchange )'F' ) ) )
        {
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = inDataATplt;
          this->dataToMountCPTplt[ this->dataListLineCTplt ] ++;
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = 0;
          return returnLCh;
        }

        this->dataListLineCTplt ++;
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
      if ( this->dataToMountCPTplt[ this->dataListLineCTplt ] != 0 )
      {
        if ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) )
        {
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = inDataATplt;
          this->dataToMountCPTplt[ this->dataListLineCTplt ] ++;
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = 0;
          return returnLCh;
        }

        this->dataListLineCTplt ++;
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
      if ( this->dataToMountCPTplt[ this->dataListLineCTplt ] != 0 )
      {
        if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'A' ) && ( inDataATplt <= ( typeDataToExchange )'Z' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'a' ) && ( inDataATplt <= ( typeDataToExchange )'z' ) ) || ( inDataATplt == ( typeDataToExchange )' ' ) )
        {
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = inDataATplt;
          this->dataToMountCPTplt[ this->dataListLineCTplt ] ++;
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = 0;
          return returnLCh;
        }

        this->dataListLineCTplt ++;
      }

      else
      {
        returnLCh = ( char ) -5;
        //StackEnum::Add( Event::PStrError );
        goto reset_pointers;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 5;
    }

    // type: surl
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'s' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'u' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'r' ) && ( *( ( *apcchPointer ) + 4 ) == ( typeDataToExchange )'l' ) )
    {
      if ( this->dataToMountCPTplt[ this->dataListLineCTplt ] != 0 )
      {
        if ( ( ( inDataATplt >= ( typeDataToExchange )'0' ) && ( inDataATplt <= ( typeDataToExchange )'9' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'A' ) && ( inDataATplt <= ( typeDataToExchange )'Z' ) ) || ( ( inDataATplt >= ( typeDataToExchange )'a' ) && ( inDataATplt <= ( typeDataToExchange )'z' ) ) || ( inDataATplt == ( typeDataToExchange )'.' ) || ( inDataATplt == ( typeDataToExchange )'_' ) || ( inDataATplt == ( typeDataToExchange )'/' ) || ( inDataATplt == ( typeDataToExchange )':' ) || ( inDataATplt == ( typeDataToExchange )'&' ) || ( inDataATplt == ( typeDataToExchange )'?' ) || ( inDataATplt == ( typeDataToExchange )'=' ) )
        {
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = inDataATplt;
          this->dataToMountCPTplt[ this->dataListLineCTplt ] ++;
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = 0;
          return returnLCh;
        }

        this->dataListLineCTplt ++;
      }

      else
      {
        returnLCh = ( char ) -7;
        //StackEnum::Add( Event::PStrError );
        goto reset_pointers;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 6;
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
      if ( this->dataToMountCPTplt[ this->dataListLineCTplt ] != 0 )
      {
        if ( ( inDataATplt != ( typeDataToExchange )'\r' ) && ( inDataATplt != ( typeDataToExchange )'\n' ) && ( inDataATplt != 0 ) )
        {
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = inDataATplt;
          this->dataToMountCPTplt[ this->dataListLineCTplt ] ++;
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = 0;
          return returnLCh;
        }

        this->dataListLineCTplt ++;
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
    this->flagSet( SEND_TO_DEVICE_FLAG_CHECK_END );
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
      this->flagSet( SEND_TO_DEVICE_FLAG_CHECK_END );
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
  this->dataListLineCTplt = 0;

  this->dataTransmitPointerLineCTplt = 0;
  this->dataReceivePointerLineCTplt = 0;

  this->flagClear( SEND_TO_DEVICE_FLAG_WAITING );
  this->flagClear( SEND_TO_DEVICE_FLAG_NEXT_STEP );
  this->flagClear( SEND_TO_DEVICE_FLAG_EVENT_SEND );

  this->flagSet( SEND_TO_DEVICE_FLAG_RUNING );
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::infinityLoop ()
{
  if ( this->flagTest( SEND_TO_DEVICE_FLAG_RUNING ) == true )
  {
    if ( this->flagTest( SEND_TO_DEVICE_FLAG_WAITING ) == false )
    {
      this->send ();
    }
  }

  else
  {
    if ( this->flagTest( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND ) == true )
    {
      this->flagClear( SEND_TO_DEVICE_FLAG_EVENT_BUFFER_SEND );
      if ( this->onBufferFullCPFnc != 0 )
      {
        this->onBufferFullCPFnc();
      }
    }

    if ( this->flagTest( SEND_TO_DEVICE_FLAG_EVENT_SEND ) == false )
    {
      this->flagSet( SEND_TO_DEVICE_FLAG_EVENT_SEND );
      //qDebug() << "On end function run";

      if ( this->onEndCPFnc != 0 )
      {
        this->sendToData = this->sendToDataOriginal;
        this->onEndCPFnc ();
      }
    }
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagSet ( char flagACh )
{
  char flagLCh = 1 << flagACh;
  this->flagsCCh |= flagLCh;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagClear ( char flagACh )
{
  char flagLCh = 1 << flagACh;
  flagLCh = ~flagLCh;
  this->flagsCCh &= flagLCh;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize>
bool SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize>::flagTest ( char flagACh )
{
  char flagLCh = 1 << flagACh;
  flagLCh = this->flagsCCh & flagLCh;

  if ( flagLCh == 0 )
  {
    return false;
  }

  return true;
}
