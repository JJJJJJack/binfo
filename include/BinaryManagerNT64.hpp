#include <BinaryManager.hpp>
#include <binfo.hpp>
#include <cstdio>
#include <winstructs.h>


template<>
class BinaryManager<IMAGE_DOS_HEADER, IMAGE_NT_HEADERS64> {
    IMAGE_DOS_HEADER dosHeader;
    IMAGE_NT_HEADERS64 ntHeaders;
    FILE *file;

    void (*printMachine)(uint16_t machine) = binfo::win::printMachine;

  public:
    BinaryManager(FILE *_file, bool *err)
        : file(_file) {
        if (binfo::fread(&dosHeader, 1, sizeof(IMAGE_DOS_HEADER), file) != 0) {
            printf("Could not read DOS header\n");
            *err = true;
            return;
        }

        if (binfo::fseek(file, dosHeader.e_lfanew, SEEK_SET) != 0) {
            printf("Could not seek to PE header\n");
            *err = true;
            return;
        }

        if (binfo::fread(&ntHeaders, 1, sizeof(IMAGE_NT_HEADERS64), file) != 0) {
            printf("Could not read NT headers\n");
            *err = true;
            return;
        }

        if (ntHeaders.Signature != IMAGE_NT_SIGNATURE) {
            printf("Invalid PE signature\n");
            *err = true;
            return;
        }
    }

    // READABLE

    void showHeaderInfo() {
        printf("PE ");

        printMachine(ntHeaders.FileHeader.Machine);
    }

    void showFileInfo() {
        binfo::win::showFileInfo(ntHeaders.FileHeader);
    }

    void showFormatInfo() {
    }

    // DATA

    void printDosHeader() {
        binfo::win::printDosHeader(dosHeader);
    }

    void printNtHeader() {
        printf("Signature: %X\n", ntHeaders.OptionalHeader.Magic);
        printf("FileHeader:\n");
        printf("\tMachine: %X\n", ntHeaders.FileHeader.Machine);
        printf("\tNumberOfSections: %X\n", ntHeaders.FileHeader.NumberOfSections);
        printf("\tTimeDateStamp: %lX\n", ntHeaders.FileHeader.TimeDateStamp);
        printf("\tPointerToSymbolTable: %lX\n",
               ntHeaders.FileHeader.PointerToSymbolTable);
        printf("\tNumberOfSymbols: %lX\n", ntHeaders.FileHeader.NumberOfSymbols);
        printf("\tSizeOfOptionalHeader: %X\n",
               ntHeaders.FileHeader.SizeOfOptionalHeader);
        printf("\tCharacteristics: %X\n", ntHeaders.FileHeader.Characteristics);

        printf("OptionalHeader:\n");
        printf("\tMagic: %X\n", ntHeaders.OptionalHeader.Magic);
        printf("\tMajorLinkerVersion: %X\n",
               ntHeaders.OptionalHeader.MajorLinkerVersion);
        printf("\tMinorLinkerVersion: %X\n",
               ntHeaders.OptionalHeader.MinorLinkerVersion);
        printf("\tSizeOfCode: %lX\n", ntHeaders.OptionalHeader.SizeOfCode);
        printf("\tSizeOfInitializedData: %lX\n",
               ntHeaders.OptionalHeader.SizeOfInitializedData);
        printf("\tSizeOfUninitializedData: %lX\n",
               ntHeaders.OptionalHeader.SizeOfUninitializedData);
        printf("\tAddressOfEntryPoint: %lX\n",
               ntHeaders.OptionalHeader.AddressOfEntryPoint);
        printf("\tBaseOfCode: %lX\n", ntHeaders.OptionalHeader.BaseOfCode);
        printf("\tImageBase: %llX\n", ntHeaders.OptionalHeader.ImageBase);
        printf("\tSectionAlignment: %lX\n",
               ntHeaders.OptionalHeader.SectionAlignment);
        printf("\tFileAlignment: %lX\n", ntHeaders.OptionalHeader.FileAlignment);
        printf("\tMajorOperatingSystemVersion: %X\n",
               ntHeaders.OptionalHeader.MajorOperatingSystemVersion);
        printf("\tMinorOperatingSystemVersion: %X\n",
               ntHeaders.OptionalHeader.MinorOperatingSystemVersion);
        printf("\tMajorImageVersion: %X\n",
               ntHeaders.OptionalHeader.MajorImageVersion);
        printf("\tMinorImageVersion: %X\n",
               ntHeaders.OptionalHeader.MinorImageVersion);
        printf("\tMajorSubsystemVersion: %X\n",
               ntHeaders.OptionalHeader.MajorSubsystemVersion);
        printf("\tMinorSubsystemVersion: %X\n",
               ntHeaders.OptionalHeader.MinorSubsystemVersion);
        printf("\tWin32VersionValue: %lX\n",
               ntHeaders.OptionalHeader.Win32VersionValue);
        printf("\tSizeOfImage: %lX\n", ntHeaders.OptionalHeader.SizeOfImage);
        printf("\tSizeOfHeaders: %lX\n", ntHeaders.OptionalHeader.SizeOfHeaders);
        printf("\tCheckSum: %lX\n", ntHeaders.OptionalHeader.CheckSum);
        printf("\tSubsystem: %X\n", ntHeaders.OptionalHeader.Subsystem);
        printf("\tDllCharacteristics: %X\n",
               ntHeaders.OptionalHeader.DllCharacteristics);
        printf("\tSizeOfStackReserve: %llX\n",
               ntHeaders.OptionalHeader.SizeOfStackReserve);
        printf("\tSizeOfStackCommit: %llX\n",
               ntHeaders.OptionalHeader.SizeOfStackCommit);
        printf("\tSizeOfHeapReserve: %llX\n",
               ntHeaders.OptionalHeader.SizeOfHeapReserve);
        printf("\tSizeOfHeapCommit: %llX\n",
               ntHeaders.OptionalHeader.SizeOfHeapCommit);
        printf("\tLoaderFlags: %lX\n", ntHeaders.OptionalHeader.LoaderFlags);
        printf("\tNumberOfRvaAndSizes: %lX\n",
               ntHeaders.OptionalHeader.NumberOfRvaAndSizes);

        printf("DataDirectory:\n");
        for (int i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++) {
            printf("\tVirtualAddress: %lX\n",
                   ntHeaders.OptionalHeader.DataDirectory[i].VirtualAddress);
            printf("\tSize: %lX\n", ntHeaders.OptionalHeader.DataDirectory[i].Size);
        }
    }
};
