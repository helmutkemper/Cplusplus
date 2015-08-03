#include "copy.h"

const char *Copy::pcchSpacer = '\0';
      char *Copy::pchSpacer  = '\0';

Copy::Copy()
{
}

void Copy::Spacer ( const char *pcchData )
{
  Copy::pcchSpacer = pcchData;
  Copy::pchSpacer  = '\0';
}

void Copy::Spacer ( char *pcchData )
{
  Copy::pchSpacer  = pcchData;
  Copy::pcchSpacer = '\0';
}

void Copy::Data ( char *chpDestination, const char *pcchData1, const char *pcchData2 )
{
  chpDestination = Copy::Data ( chpDestination, pcchData1 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pcchData2 );

  Copy::pcchSpacer = '\0';
  Copy::pchSpacer  = '\0';
}

void Copy::Data ( char *chpDestination, const char *pcchData1, char *pchData2 )
{
  chpDestination = Copy::Data ( chpDestination, pcchData1 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData2 );

  Copy::pcchSpacer = '\0';
  Copy::pchSpacer  = '\0';
}

void Copy::Data ( char *chpDestination, const char *pcchData1, char *pchData2, char *pchData3 )
{
  chpDestination = Copy::Data ( chpDestination, pcchData1 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData2 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData3 );

  Copy::pcchSpacer = '\0';
  Copy::pchSpacer  = '\0';
}

void Copy::Data ( char *chpDestination, const char *pcchData1, char *pchData2, char *pchData3, char *pchData4 )
{
  chpDestination = Copy::Data ( chpDestination, pcchData1 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData2 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData3 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  Copy::Data ( chpDestination, pchData4 );

  Copy::pcchSpacer = '\0';
  Copy::pchSpacer  = '\0';
}

void Copy::Data ( char *chpDestination, const char *pcchData1, char *pchData2, char *pchData3, char *pchData4, char *pchData5 )
{
  chpDestination = Copy::Data ( chpDestination, pcchData1 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData2 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData3 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData4 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData5 );

  Copy::pcchSpacer = '\0';
  Copy::pchSpacer  = '\0';
}

void Copy::Data ( char *chpDestination, const char *pcchData1, char *pchData2, char *pchData3, char *pchData4, char *pchData5, char *pchData6 )
{
  chpDestination = Copy::Data ( chpDestination, pcchData1 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData2 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData3 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData4 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData5 );

  chpDestination = Copy::Data ( chpDestination, pcchSpacer );
  chpDestination = Copy::Data ( chpDestination, pchSpacer );

  chpDestination = Copy::Data ( chpDestination, pchData6 );

  Copy::pcchSpacer = '\0';
  Copy::pchSpacer  = '\0';
}

char* Copy::Data ( char *chpDestination, const char *pcchData1 )
{
  if ( pcchData1 == '\0' )
  {
    return chpDestination;
  }

  while ( *chpDestination != '\0' )
  {
    chpDestination += 1;
  }

  do
  {
    *chpDestination = *pcchData1;
    chpDestination += 1;
    pcchData1 += 1;
  }
  while ( *pcchData1 != '\0' );

  *chpDestination = '\0';

  return chpDestination;
}

char* Copy::Data ( char *chpDestination, char *pchData1 )
{
  if ( pchData1 == '\0' )
  {
    return chpDestination;
  }

  while ( *chpDestination != '\0' )
  {
    chpDestination += 1;
  }

  do
  {
    *chpDestination = *pchData1;
    chpDestination += 1;
    pchData1 += 1;
  }
  while ( *pchData1 != '\0' );

  *chpDestination = '\0';

  return chpDestination;
}
