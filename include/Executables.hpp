#ifndef Executables_hpp
#define Executables_hpp

#include <BinaryManager.hpp>
#include <linuxstructs.h>
#include <winstructs.h>

typedef union {
    BinaryManager<IMAGE_DOS_HEADER, IMAGE_NT_HEADERS32> *dosNt32;
    BinaryManager<IMAGE_DOS_HEADER, IMAGE_NT_HEADERS64> *dosNt64;
    BinaryManager<Elf32_Ehdr> *elf32;
    BinaryManager<Elf64_Ehdr> *elf64;
} Executables;

#endif
