#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <stdio.h>
#include <QDebug>
#include <direct.h>

class FileSystem
{
  public:
    FileSystem();
    static void makeDir ( const char *dirPathAPCCr );
    void copy( const char *fileSourceAPCCh, const char *fileDestinationAPCCh );
    void listDir( const char *dirPathAPCCr );
    bool isFolder ( const char *dirPathAPCCr );
    bool isFile( const char *dirPathAPCCr );
    void dirRemove( const char *dirPathAPCCr, unsigned char pathLengthAUCh );
    ~FileSystem();
};

#endif // FILESYSTEM_H
