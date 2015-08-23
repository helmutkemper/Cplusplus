#include "typeskemper.h"
#include "RingMemory.h"

template <class DataTypeTplt, class DataSizeTplt>
RingMemory<DataTypeTplt, DataSizeTplt>::RingMemory ( DataSizeTplt sizeATplt )
{
  this->memoryCTplt    = new DataTypeTplt[ sizeATplt ];
  this->sizeCTplt      = sizeATplt;

  this->dataPointerIn  = 0;
  this->dataPointerOut = 0;

  this->onErrorAdd     = 0;
  this->onErrorGet     = 0;
}

template <class DataTypeTplt, class DataSizeTplt>
void RingMemory<DataTypeTplt, DataSizeTplt>::add( DataTypeTplt dataATplt )
{
  this->memoryCTplt[ this->dataPointerIn ] = dataATplt;

  if ( this->dataPointerIn >= ( this->sizeCTplt -1 ) )
  {
    this->dataPointerIn  = 0;
  }

  else
  {
    this->dataPointerIn += 1;
  }

  if ( this->onErrorAdd != 0 )
  {
    if ( this->dataPointerIn == this->dataPointerOut )
    {
      this->onErrorAdd ();
    }
  }
}

template <class DataTypeTplt, class DataSizeTplt>
DataTypeTplt RingMemory<DataTypeTplt, DataSizeTplt>::get()
{
  DataTypeTplt returnLTplt = this->memoryCTplt[ this->dataPointerOut ];

  if ( this->onErrorGet != 0 )
  {
    if (this->dataPointerIn == this->dataPointerOut)
    {
      this->onErrorGet ();
    }
  }

  if ( this->dataPointerOut >= ( this->sizeCTplt -1 ) )
  {
    this->dataPointerOut  = 0;
  }

  else
  {
    this->dataPointerOut += 1;
  }

  return returnLTplt;
}

template <class DataTypeTplt, class DataSizeTplt>
DataTypeTplt RingMemory<DataTypeTplt, DataSizeTplt>::read( DataSizeTplt addressATplt )
{
  if ( addressATplt > ( this->sizeCTplt -1 ) )
  {
    if ( this->onErrorGet != 0 )
    {
      if (this->dataPointerIn == this->dataPointerOut)
      {
        this->onErrorGet ();
        addressATplt = ( this->sizeCTplt -1 );
      }
    }
  }

  return this->memoryCTplt[ addressATplt ];
}

template <class DataTypeTplt, class DataSizeTplt>
DataTypeTplt RingMemory<DataTypeTplt, DataSizeTplt>::readLast()
{
  DataSizeTplt addressLTplt = this->dataPointerIn;

  if ( addressLTplt == 0 )
  {
    addressLTplt = this->sizeCTplt -1;
  }
  else
  {
    addressLTplt -= 1;
  }

  return this->memoryCTplt[ addressLTplt ];
}

template <class DataTypeTplt, class DataSizeTplt>
void RingMemory<DataTypeTplt, DataSizeTplt>::reset ()
{
  this->dataPointerIn  = 0;
  this->dataPointerOut = 0;

  for ( DataSizeTplt i = 0; i != this->sizeCTplt; i++ )
  {
    this->memoryCTplt[ i ] = 0;
  }
}

template <class DataTypeTplt, class DataSizeTplt>
void RingMemory<DataTypeTplt, DataSizeTplt>::onErrorAddEvent ( PT_VOID_VOID functionAVdVdPt )
{
  this->onErrorAdd = functionAVdVdPt;
}

template <class DataTypeTplt, class DataSizeTplt>
void RingMemory<DataTypeTplt, DataSizeTplt>::onErrorGetEvent ( PT_VOID_VOID functionAVdVdPt )
{
  this->onErrorGet = functionAVdVdPt;
}

template <class DataTypeTplt, class DataSizeTplt>
RingMemory<DataTypeTplt, DataSizeTplt>::~RingMemory()
{
  delete[] this->memoryCTplt;
}
