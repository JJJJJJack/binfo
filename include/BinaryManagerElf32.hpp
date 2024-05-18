#include <BinaryManager.hpp>
#include <binfo.hpp>
#include <cstdio>
#include <linuxstructs.h>

template<>
class BinaryManager<Elf32_Ehdr> {
    Elf32_Ehdr header;
    Elf32_Phdr program;
    FILE *file;

    void (*printMachine)(uint16_t machine) = binfo::linux::elfPrintMachine;

  public:
    BinaryManager(FILE *_file, bool *err)
        : file(_file) {
        if (binfo::fread(&header, 1, sizeof(Elf32_Ehdr), file) != 0) {
            printf("Could not read ELF header\n");
            *err = true;
            return;
        }
    }

    void showHeaderInfo() {
        printf("ELF 32-bit ");

        printMachine(header.e_machine);
    }

    void showFormatInfo() {
        ;
    }
};
