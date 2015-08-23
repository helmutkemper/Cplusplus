#ifndef TYPES_KEMPER_H
#define TYPES_KEMPER_H

  #ifndef __PT_VOID_VOID
  #define __PT_VOID_VOID
    extern "C"
    {
      typedef void ( * PT_VOID_VOID ) ();
    }
  #endif // PT_VOID_VOID

  #ifndef __UINT_1B
  #define __UINT_1B
    extern "C"
    {
      typedef unsigned char UINT_1B;
    }
  #endif // __UINT_1B

  #ifndef __UINT_2B
  #define __UINT_2B
    extern "C"
    {
      typedef unsigned short UINT_2B;
    }
  #endif // __UINT_2B

  #ifndef __UINT_4B
  #define __UINT_4B
    extern "C"
    {
      typedef unsigned long UINT_4B;
    }
  #endif // __UINT_4B

#endif // TYPES_KEMPER_H
