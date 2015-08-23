#include "SendToDevice.h"

template <class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::SendToDevice( typeStackStepsSize stackStepsSizeAUCh, typeStackDataSize stackDataSizeAUCh )
{
  this->dataToMountCPTplt      = new typeDataToMountBeforeExchange*[ stackDataSizeAUCh ];
  this->dataTransmitCPTplt = new typeDataToExchange*[ stackStepsSizeAUCh ];
  this->dataReceiveCPTplt = new typeDataToExchange*[ stackStepsSizeAUCh ];

  this->stackStepsSizeCTplt = stackStepsSizeAUCh;
  this->stackDataSizeCTplt  = stackDataSizeAUCh;

  this->dataTransmitPointerLineCTplt = 0;
  this->dataReceivePointerLineCTplt = 0;

  this->dataListLineCTplt   = 0;
  //this->siGenericCounter = 0;

  this->sendCPFnc  = 0;
  this->makeComplementaryGetCPFnc = 0;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::clear()
{
  for ( unsigned char i = 0; i != this->stackStepsSizeCTplt; i += 1 )
  {
    this->dataTransmitCPTplt[ i ] = 0;
    this->dataReceiveCPTplt[ i ] = 0;
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::addReceiveData ( typeStackStepsSize addressAUCh, typeDataToExchange *dataACSChP )
{
  if ( this->stackStepsSizeCTplt <= addressAUCh )
  {
    return;
  }

  this->dataReceiveCPTplt[ addressAUCh ] = dataACSChP;

  if ( addressAUCh + 1 <= this->stackStepsSizeCTplt )
  {
    this->dataReceiveCPTplt[ addressAUCh + 1 ] = 0;
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::addTransmitData ( typeStackStepsSize addressAUCh, typeDataToExchange *dataACSChP )
{
  if ( this->stackStepsSizeCTplt <= addressAUCh )
  {
    return;
  }

  this->dataTransmitCPTplt[ addressAUCh ] = dataACSChP;

  if ( addressAUCh + 1 <= this->stackStepsSizeCTplt )
  {
    this->dataTransmitCPTplt[ addressAUCh + 1 ] = 0;
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::addPointer ( typeStackDataSize addressAUCh, typeDataToMountBeforeExchange *dataASCh )
{
  if ( this->stackDataSizeCTplt <= addressAUCh )
  {
    return;
  }

  this->dataToMountCPTplt[ addressAUCh ] = dataASCh;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::setSendFunction ( PT_VOID_CH functPointerAPFn )
{
  this->sendCPFnc = functPointerAPFn;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::setComplemetaryGetFunction ( PT_VOID_CH functPointerAPFn )
{
  this->makeComplementaryGetCPFnc = functPointerAPFn;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::~SendToDevice()
{
  delete[] this->dataTransmitCPTplt;
  delete[] this->dataReceiveCPTplt;
  delete[] this->dataToMountCPTplt;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::send ()
{
  char dataToSendLCh;
  typeDataToMountBeforeExchange *userDataLPCh = '\0';

  while ( true )
  {
    dataToSendLCh = *this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ];

    if ( dataToSendLCh == '\0' )
    {
      this->dataTransmitPointerLineCTplt ++;

      //if ( ( this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] == '\0' ) && ( this->dataReceiveCPTplt[ this->dataTransmitPointerLineCTplt ] == '\0' ) )
      if ( this->dataTransmitCPTplt[ this->dataTransmitPointerLineCTplt ] == '\0' )
      {
        StackEnum::Add( Event::EndProcess );
        this->flagClear( SEND_TO_DEVICE_FLAG_RUNING );
        return;
      }

      else
      {
        if ( this->dataReceiveCPTplt[ this->dataReceivePointerLineCTplt ] == '\0' )
        {
          this->flagSet( SEND_TO_DEVICE_FLAG_PROCCESS_END );
        }
        else
        {
          this->flagSet( SEND_TO_DEVICE_FLAG_WAITING );
        }
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

    if ( this->sendCPFnc != '\0' )
    {
      if ( userDataLPCh != '\0' )
      {
        while ( *userDataLPCh != '\0' )
        {
          this->sendCPFnc ( *userDataLPCh );
          userDataLPCh ++;
        }
        userDataLPCh = '\0';
      }

      else
      {
        this->sendCPFnc ( dataToSendLCh );
      }
    }
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::onIncomingData ( typeDataToExchange achChar )
{
  // Maquina de estados - inicio ->
  if ( this->dataReceiveCPTplt[ this->dataReceivePointerLineCTplt ] != '\0' )
  {
    if ( *this->dataReceiveCPTplt[ this->dataReceivePointerLineCTplt ] == achChar )
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

  if ( this->makeComplementaryGetCPFnc != 0 )
  {
    this->makeComplementaryGetCPFnc ( achChar );
  }
}

/**
 * @brief SendToDevice::testChar
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
 * @param achRx
 * @param e
 * @return
 */
template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
bool SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::testChar ( typeDataToExchange **apcchPointer, typeDataToExchange *apcchPointerStart, typeDataToMountBeforeExchange achRx, typeTestEvent e )
{
  restart_process:
  if ( **apcchPointer == ( typeDataToExchange )'{' )
  {
    // type: time
    if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'t' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'i' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'m' ) && ( *( ( *apcchPointer ) + 4 ) == ( typeDataToExchange )'e' ) )
    {
      if ( this->dataToMountCPTplt[ this->dataListLineCTplt ] != 0 )
      {
        if ( ( ( achRx >= ( typeDataToExchange )'0' ) && ( achRx <= ( typeDataToExchange )'9' ) ) || ( achRx == ( typeDataToExchange )':' ) || ( achRx == ( typeDataToExchange )'/' ) )
        {
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = achRx;
          this->dataToMountCPTplt[ this->dataListLineCTplt ] ++;
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = 0;
          return true;
        }

        this->dataListLineCTplt ++;
      }

      else
      {
        StackEnum::Add( Event::PTimeError );
        goto reset_pointers;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 6;
    }

    // type: inum
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'i' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'n' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'u' ) && ( *( ( *apcchPointer ) + 4 ) == ( typeDataToExchange )'m' ) )
    {
      if ( ( ( achRx >= ( typeDataToExchange )'0' ) && ( achRx <= ( typeDataToExchange )'9' ) ) || ( achRx == ( typeDataToExchange )'+' ) || ( achRx == ( typeDataToExchange )'-' ) )
      {
        return true;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 6;
    }

    // type: snum
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'s' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'n' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'u' ) && ( *( ( *apcchPointer ) + 4 ) == ( typeDataToExchange )'m' ) )
    {
      if ( this->dataToMountCPTplt[ this->dataListLineCTplt ] != '\0' )
      {
        if ( ( ( achRx >= ( typeDataToExchange )'0' ) && ( achRx <= ( typeDataToExchange )'9' ) ) || ( achRx == ( typeDataToExchange )'+' ) || ( achRx == ( typeDataToExchange )'-' ) )
        {
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = achRx;
          this->dataToMountCPTplt[ this->dataListLineCTplt ] ++;
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = 0;
          return true;
        }

        this->dataListLineCTplt ++;
      }

      else
      {
        StackEnum::Add( Event::PSNumError );
        goto reset_pointers;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 6;
    }

    // type: hex
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'h' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'e' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'x' ) )
    {
      if ( this->dataToMountCPTplt[ this->dataListLineCTplt ] != 0 )
      {
        if ( ( ( achRx >= ( typeDataToExchange )'0' ) && ( achRx <= ( typeDataToExchange )'9' ) ) || ( ( achRx >= ( typeDataToExchange )'a' ) && ( achRx <= ( typeDataToExchange )'f' ) ) || ( ( achRx >= ( typeDataToExchange )'A' ) && ( achRx <= ( typeDataToExchange )'F' ) ) )
        {
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = achRx;
          this->dataToMountCPTplt[ this->dataListLineCTplt ] ++;
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = 0;
          return true;
        }

        this->dataListLineCTplt ++;
      }

      else
      {
        StackEnum::Add( Event::PSHexError );
        goto reset_pointers;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 5;
    }

    // type: num
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'n' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'u' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'m' ) )
    {
      if ( this->dataToMountCPTplt[ this->dataListLineCTplt ] != 0 )
      {
        if ( ( achRx >= ( typeDataToExchange )'0' ) && ( achRx <= ( typeDataToExchange )'9' ) )
        {
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = achRx;
          this->dataToMountCPTplt[ this->dataListLineCTplt ] ++;
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = 0;
          return true;
        }

        this->dataListLineCTplt ++;
      }

      else
      {
        StackEnum::Add( Event::PNumError );
        goto reset_pointers;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 5;
    }

    // type: str
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'s' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'t' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'r' ) )
    {
      if ( this->dataToMountCPTplt[ this->dataListLineCTplt ] != 0 )
      {
        if ( ( ( achRx >= ( typeDataToExchange )'0' ) && ( achRx <= ( typeDataToExchange )'9' ) ) || ( ( achRx >= ( typeDataToExchange )'A' ) && ( achRx <= ( typeDataToExchange )'Z' ) ) || ( ( achRx >= ( typeDataToExchange )'a' ) && ( achRx <= ( typeDataToExchange )'z' ) ) || ( achRx == ( typeDataToExchange )' ' ) )
        {
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = achRx;
          this->dataToMountCPTplt[ this->dataListLineCTplt ] ++;
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = 0;
          return true;
        }

        this->dataListLineCTplt ++;
      }

      else
      {
        StackEnum::Add( Event::PStrError );
        goto reset_pointers;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 5;
    }

    // type: inum
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'i' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'s' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'t' ) && ( *( ( *apcchPointer ) + 4 ) == ( typeDataToExchange )'r' ) )
    {
      if ( ( ( achRx >= ( typeDataToExchange )'0' ) && ( achRx <= ( typeDataToExchange )'9' ) ) || ( ( achRx >= ( typeDataToExchange )'A' ) && ( achRx <= ( typeDataToExchange )'Z' ) ) || ( ( achRx >= ( typeDataToExchange )'a' ) && ( achRx <= ( typeDataToExchange )'z' ) ) || ( achRx == ( typeDataToExchange )' ' ) )
      {
        return true;
      }

      ( *apcchPointer ) = ( *apcchPointer ) + 6;
    }

    // type: all
    else if ( ( *( ( *apcchPointer ) + 1 ) == ( typeDataToExchange )'a' ) && ( *( ( *apcchPointer ) + 2 ) == ( typeDataToExchange )'l' ) && ( *( ( *apcchPointer ) + 3 ) == ( typeDataToExchange )'l' ) )
    {
      if ( this->dataToMountCPTplt[ this->dataListLineCTplt ] != 0 )
      {
        if ( ( achRx != ( typeDataToExchange )'\r' ) && ( achRx != ( typeDataToExchange )'\n' ) && ( achRx != 0 ) )
        {
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = achRx;
          this->dataToMountCPTplt[ this->dataListLineCTplt ] ++;
          *this->dataToMountCPTplt[ this->dataListLineCTplt ] = 0;
          return true;
        }

        this->dataListLineCTplt ++;
      }

      else
      {
        StackEnum::Add( Event::PAllError );
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
    StackEnum::Add( e );
    goto reset_pointers;
  }

  else if ( ( **apcchPointer == achRx ) || ( **apcchPointer == 0 ) )
  {
    ( *apcchPointer ) ++;

    if ( **apcchPointer == 0 )
    {
      ( *apcchPointer ) = apcchPointerStart;
      this->flagSet( SEND_TO_DEVICE_FLAG_CHECK_END );
      StackEnum::Add( e );
      goto reset_pointers;
    }

    return true;
  }

  reset_pointers:
    ( *apcchPointer ) = apcchPointerStart;
    return false;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::run ()
{
  this->dataListLineCTplt = 0;

  this->dataTransmitPointerLineCTplt = 0;
  this->dataReceivePointerLineCTplt = 0;

  this->flagClear( SEND_TO_DEVICE_FLAG_WAITING );
  this->flagClear( SEND_TO_DEVICE_FLAG_NEXT_STEP );

  this->flagSet( SEND_TO_DEVICE_FLAG_RUNING );
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::infinityLoop ()
{
  if ( this->flagTest( SEND_TO_DEVICE_FLAG_RUNING ) == true )
  {
    if ( this->flagTest( SEND_TO_DEVICE_FLAG_WAITING ) == false )
    {
      this->send ();
    }
  }
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::flagSet ( char flagACh )
{
  char flagLCh = 1 << flagACh;
  this->flagsCCh |= flagLCh;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
void SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::flagClear ( char flagACh )
{
  char flagLCh = 1 << flagACh;
  flagLCh = ~flagLCh;
  this->flagsCCh &= flagLCh;
}

template<class typeDataToExchange, class typeDataToMountBeforeExchange, class typeStackStepsSize, class typeStackDataSize, class typeTestEvent>
bool SendToDevice<typeDataToExchange, typeDataToMountBeforeExchange, typeStackStepsSize, typeStackDataSize, typeTestEvent>::flagTest ( char flagACh )
{
  char flagLCh = 1 << flagACh;
  flagLCh = this->flagsCCh & flagLCh;

  if ( flagLCh == 0 )
  {
    return false;
  }

  return true;
}
