#include "FileSystem.h"

FileSystem::FileSystem()
{

}

FileSystem::~FileSystem()
{

}

void FileSystem::makeDir ( const char *dirPathAPCCr )
{
  mkdir( dirPathAPCCr, 0777 );
}

void FileSystem::copy( const char *fileSourceAPCCh, const char *fileDestinationAPCCh )
{
  int contentLSInt;

  FILE *fileOpenResourceLPFl = fopen( fileSourceAPCCh, "r" );   // src file
  FILE *fileCloseResourceLPFl = fopen( fileDestinationAPCCh, "w" );   // dest file

  while ( true )
  {
    contentLSInt = fgetc( fileOpenResourceLPFl );
    if ( contentLSInt == EOF )
    {
      break;
    }
    fputc( contentLSInt, fileCloseResourceLPFl );
  }
  fclose( fileOpenResourceLPFl );
  fclose( fileCloseResourceLPFl );
}

void FileSystem::listDir( const char *dirPathAPCCr )
{
    DIR *dirResourceLPDr = opendir( dirPathAPCCr );
    struct dirent *dirLStt;

    while ( ( dirLStt = readdir( dirResourceLPDr ) ) != NULL )
    {
      printf( "%s\n", dirLStt->d_name );
    }
    closedir( dirResourceLPDr );
}

bool FileSystem::isFolder ( const char *dirPathAPCCr )
{
  DIR *dirResourceLPDr = opendir( dirPathAPCCr );
  if ( dirResourceLPDr )
  {
    closedir( dirResourceLPDr );
  }
  return ( dirResourceLPDr != NULL );
}

bool FileSystem::isFile( const char *dirPathAPCCr )
{
  FILE *fileOpenResourceLPFl = fopen( dirPathAPCCr, "r" );
  if ( fileOpenResourceLPFl )
  {
    fclose( fileOpenResourceLPFl );
  }
  return ( fileOpenResourceLPFl != NULL );
}

void FileSystem::dirRemove( const char *dirPathAPCCr, unsigned char pathLengthAUCh )
{
  DIR *dirResourceLPDr = opendir( dirPathAPCCr );
  struct dirent *dirLStt;

  char *path = new char [ pathLengthAUCh ] = { 0 };
  while( ( dirLStt = readdir( dirResourceLPDr ) ) != NULL )
  {
    strcpy( path, dirPathAPCCr );
    strcat( path, "/" );
    strcat( path, dirLStt->d_name );
    remove( path );
  }
  delete[] path;
  closedir( dirResourceLPDr );
  remove( dirPathAPCCr );
}
