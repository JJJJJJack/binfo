#ifndef binfo_hpp
#define binfo_hpp

#include <linuxstructs.h>
#include <winstructs.h>

#include <cstdint>
#include <cstdio>

namespace binfo {
    namespace linux {
        int linuxBinfo(FILE *file);
        int checkElfBitness(FILE *file);
        void elfPrintMachine(uint16_t machine);
    } // namespace linux

    namespace win {
        int winBinfo(FILE *file);
        void printMachine(uint16_t machine);
        void printDosHeader(IMAGE_DOS_HEADER dosHeader);
        void showFileInfo(IMAGE_FILE_HEADER fileHeader);
    } // namespace win

    // FILE wrappers

    FILE *fopen(const char *_FileName, const char *_Mode);
    int fread(void *_Buffer, size_t _ElementSize, size_t _ElementCount, FILE *_Stream);
    int fseek(FILE *_Stream, long _Offset, int _Origin);
    int freadAndSeek0(void *_Buffer, size_t _ElementSize, size_t _ElementCount, FILE *_Stream);

    // FILES UTILS

    int openFile(const char *filename, FILE **file);

} // namespace binfo

#endif
