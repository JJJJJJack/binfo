#ifndef wintypes_h
#define wintypes_h

#include <cstdint>

#define __LONG32 int32_t

typedef char CHAR;
typedef short SHORT;
typedef __LONG32 LONG;
typedef int INT;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef uint32_t DWORD;
typedef float FLOAT;
typedef FLOAT *PFLOAT;
typedef BYTE *PBYTE;
typedef BYTE *LPBYTE;
typedef int *PINT;
typedef int *LPINT;
typedef WORD *PWORD;
typedef WORD *LPWORD;
typedef __LONG32 *LPLONG;
typedef DWORD *PDWORD;
typedef DWORD *LPDWORD;
typedef void *LPVOID;

typedef int64_t LONGLONG;
typedef uint64_t ULONGLONG;

#endif
