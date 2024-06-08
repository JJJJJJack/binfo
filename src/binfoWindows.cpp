#include "binfo.hpp"
#include <BinaryManager.hpp>
#include <BinaryManagerNT32.hpp>
#include <BinaryManagerNT64.hpp>
#include <Executables.hpp>

#include <cstdint>
#include <cstdio>
#include <winstructs.h>

namespace binfo {
    namespace win {
        int winBinfo(FILE *file) {
            IMAGE_DOS_HEADER dosHeader;
            Executables e;
            DWORD peSignature;
            WORD machine;
            bool err = false;

            if (binfo::fread(&dosHeader, 1, sizeof(IMAGE_DOS_HEADER), file) != 0) {
                printf("Could not read DOS header\n");
                return 1;
            }

            // binfo::win::printDosHeader(dosHeader);
            // printf("asdasdas %lld\n", sizeof(dosHeader.e_lfanew));
            // return 0;
            if (binfo::fseek(file, dosHeader.e_lfanew, SEEK_SET) != 0) {
                printf("Could not seek to PE header\n");
                printf(
                    "e_magic: %p\n"
                    "e_lfanew: %p\n",
                    &dosHeader.e_magic,
                    &dosHeader.e_lfanew);
                return 1;
            }

            if (binfo::fread(&peSignature, 1, sizeof(DWORD), file) != 0) {
                printf("Could not read PE signature\n");
                return 1;
            }

            if (peSignature != IMAGE_NT_SIGNATURE) {
                printf("Invalid PE signature\n");
                return 1;
            }

            if (binfo::freadAndSeek0(&machine, 1, sizeof(WORD), file) != 0) {
                printf("Could not read machine type\n");
                return 1;
            }

            switch (machine) {
                case IMAGE_FILE_MACHINE_AMD64:
                    e.dosNt64 = new BinaryManager<IMAGE_DOS_HEADER, IMAGE_NT_HEADERS64>(file, &err);
                    if (err) {
                        return 1;
                    }

                    e.dosNt64->showHeaderInfo();
                    // e.dosNt64->printNtHeader();
                    e.dosNt64->showFileInfo();

                    return 0;
                case IMAGE_FILE_MACHINE_I386:
                    e.dosNt32 = new BinaryManager<IMAGE_DOS_HEADER, IMAGE_NT_HEADERS32>(file, &err);
                    if (err) {
                        return 1;
                    }

                    e.dosNt32->showHeaderInfo();
                    // e.dosNt32->printNtHeader();
                    e.dosNt32->showFileInfo();

                    return 0;
                case IMAGE_FILE_MACHINE_IA64:
                    // TO BE IMPLEMENTED... (need `IMAGE_OPTIONAL_HEADER_EXTENDED_INFO`)
                    break;
                // THESE ARE NOT MENTIONED IN THE learn.microsoft.com DOCS
                // BUT ARE DEFINED IN THE windows headers
                case 0x160:
                    break;
                case IMAGE_FILE_MACHINE_R3000:
                case IMAGE_FILE_MACHINE_R4000:
                case IMAGE_FILE_MACHINE_R10000:
                    break;
                case IMAGE_FILE_MACHINE_WCEMIPSV2:
                    break;
                case IMAGE_FILE_MACHINE_ALPHA:
                    break;
                case IMAGE_FILE_MACHINE_SH3:
                    break;
                case IMAGE_FILE_MACHINE_SH3DSP:
                    break;
                case IMAGE_FILE_MACHINE_SH3E:
                    break;
                case IMAGE_FILE_MACHINE_SH4:
                    break;
                case IMAGE_FILE_MACHINE_SH5:
                    break;
                case IMAGE_FILE_MACHINE_ARM:
                    break;
                case IMAGE_FILE_MACHINE_THUMB:
                    break;
                case IMAGE_FILE_MACHINE_ARMNT:
                    break;
                case IMAGE_FILE_MACHINE_AM33:
                    break;
                case IMAGE_FILE_MACHINE_POWERPC:
                    break;
                case IMAGE_FILE_MACHINE_POWERPCFP:
                    break;
                case IMAGE_FILE_MACHINE_MIPS16:
                case IMAGE_FILE_MACHINE_MIPSFPU:
                case IMAGE_FILE_MACHINE_MIPSFPU16:
                    break;
                case IMAGE_FILE_MACHINE_ALPHA64:
                    break;
                case IMAGE_FILE_MACHINE_TRICORE:
                    break;
                case IMAGE_FILE_MACHINE_CEF:
                    break;
                case IMAGE_FILE_MACHINE_EBC:
                    break;
                case IMAGE_FILE_MACHINE_M32R:
                    break;
                case IMAGE_FILE_MACHINE_ARM64:
                    break;
                case IMAGE_FILE_MACHINE_CEE:
                    break;
                default:
                    return -1;
            }

            return 0;
        }

        void printMachine(uint16_t machine) {
            switch (machine) {
                case IMAGE_FILE_MACHINE_I386:
                    printf("x86 ");
                    break;
                case IMAGE_FILE_MACHINE_AMD64:
                    printf("x86-64 ");
                    break;
                case 0x160:
                    printf("MIPS big-endian ");
                    break;
                case IMAGE_FILE_MACHINE_R3000:
                case IMAGE_FILE_MACHINE_R4000:
                case IMAGE_FILE_MACHINE_R10000:
                    printf("MIPS little-endian ");
                    break;
                case IMAGE_FILE_MACHINE_WCEMIPSV2:
                    printf("MIPS little-endian WCE v2 ");
                    break;
                case IMAGE_FILE_MACHINE_ALPHA:
                    printf("Alpha_AXP ");
                    break;
                case IMAGE_FILE_MACHINE_SH3:
                    printf("SH3 little-endian ");
                    break;
                case IMAGE_FILE_MACHINE_SH3DSP:
                    printf("SH3DSP ");
                    break;
                case IMAGE_FILE_MACHINE_SH3E:
                    printf("SH3E little-endian ");
                    break;
                case IMAGE_FILE_MACHINE_SH4:
                    printf("SH4 little-endian ");
                    break;
                case IMAGE_FILE_MACHINE_SH5:
                    printf("SH5 ");
                    break;
                case IMAGE_FILE_MACHINE_ARM:
                    printf("ARM Little-Endian ");
                    break;
                case IMAGE_FILE_MACHINE_THUMB:
                    printf("ARM Thumb/Thumb-2 Little-Endian ");
                    break;
                case IMAGE_FILE_MACHINE_ARMNT:
                    printf("ARM Thumb-2 Little-Endian ");
                    break;
                case IMAGE_FILE_MACHINE_AM33:
                    printf("AM33 ");
                    break;
                case IMAGE_FILE_MACHINE_POWERPC:
                    printf("IBM PowerPC Little-Endian ");
                    break;
                case IMAGE_FILE_MACHINE_POWERPCFP:
                    printf("IBM PowerPC FP Little-Endian ");
                    break;
                case IMAGE_FILE_MACHINE_IA64:
                    printf("Intel 64 ");
                    break;
                case IMAGE_FILE_MACHINE_MIPS16:
                case IMAGE_FILE_MACHINE_MIPSFPU:
                case IMAGE_FILE_MACHINE_MIPSFPU16:
                    printf("MIPS ");
                    break;
                case IMAGE_FILE_MACHINE_ALPHA64:
                    printf("ALPHA64 ");
                    break;
                case IMAGE_FILE_MACHINE_TRICORE:
                    printf("Infineon ");
                    break;
                case IMAGE_FILE_MACHINE_CEF:
                    printf("CEF ");
                    break;
                case IMAGE_FILE_MACHINE_EBC:
                    printf("EFI Byte Code ");
                    break;
                case IMAGE_FILE_MACHINE_M32R:
                    printf("M32R little-endian ");
                    break;
                case IMAGE_FILE_MACHINE_ARM64:
                    printf("ARM64 Little-Endian ");
                    break;
                case IMAGE_FILE_MACHINE_CEE:
                    printf("CEE ");
                    break;
                default:
                    printf("Unknown machine type (%X)\n", machine);
            }
        }

        void printDosHeader(IMAGE_DOS_HEADER dosHeader) {
            uint8_t offset = 0;

            printf("%X: e_magic: %X\n", offset, dosHeader.e_magic);
            offset += sizeof(dosHeader.e_magic);
            printf("%X: e_cblp: %X\n", offset, dosHeader.e_cblp);
            offset += sizeof(dosHeader.e_cblp);
            printf("%X: e_cp: %X\n", offset, dosHeader.e_cp);
            offset += sizeof(dosHeader.e_cp);
            printf("%X: e_crlc: %X\n", offset, dosHeader.e_crlc);
            offset += sizeof(dosHeader.e_crlc);
            printf("%X: e_cparhdr: %X\n", offset, dosHeader.e_cparhdr);
            offset += sizeof(dosHeader.e_cparhdr);
            printf("%X: e_minalloc: %X\n", offset, dosHeader.e_minalloc);
            offset += sizeof(dosHeader.e_minalloc);
            printf("%X: e_maxalloc: %X\n", offset, dosHeader.e_maxalloc);
            offset += sizeof(dosHeader.e_maxalloc);
            printf("%X: e_ss: %X\n", offset, dosHeader.e_ss);
            offset += sizeof(dosHeader.e_ss);
            printf("%X: e_sp: %X\n", offset, dosHeader.e_sp);
            offset += sizeof(dosHeader.e_sp);
            printf("%X: e_csum: %X\n", offset, dosHeader.e_csum);
            offset += sizeof(dosHeader.e_csum);
            printf("%X: e_ip: %X\n", offset, dosHeader.e_ip);
            offset += sizeof(dosHeader.e_ip);
            printf("%X: e_cs: %X\n", offset, dosHeader.e_cs);
            offset += sizeof(dosHeader.e_cs);
            printf("%X: e_lfarlc: %X\n", offset, dosHeader.e_lfarlc);
            offset += sizeof(dosHeader.e_lfarlc);
            printf("%X: e_ovno: %X\n", offset, dosHeader.e_ovno);
            offset += sizeof(dosHeader.e_ovno);

            printf("e_res:\n");
            for (int i = 0; i < 4; i++) {
                printf("%X: \t%X\n", offset, dosHeader.e_res[i]);
                offset += sizeof(dosHeader.e_res[i]);
            }

            printf("%X: e_oemid: %X\n", offset, dosHeader.e_oemid);
            offset += sizeof(dosHeader.e_oemid);
            printf("%X: e_oeminfo: %X\n", offset, dosHeader.e_oeminfo);
            offset += sizeof(dosHeader.e_oeminfo);

            printf("e_res2:\n");
            for (int i = 0; i < 10; i++) {
                printf("%X: \t%X\n", offset, dosHeader.e_res2[i]);
                offset += sizeof(dosHeader.e_res2[i]);
            }

            printf("%X: e_lfanew: %lX\n", offset, dosHeader.e_lfanew);
        }

        void showFileInfo(IMAGE_FILE_HEADER fileHeader) {
            printf("Sections %u; ", fileHeader.NumberOfSections);

            if (fileHeader.PointerToSymbolTable == 0) {
                printf("COFF symbol table do not exists; ");
            } else {
                printf("COFF symbol table exists; ");
            }

            printf("Symbols %lu; ", fileHeader.NumberOfSymbols);
            printf("Optional header size %u; ", fileHeader.SizeOfOptionalHeader);

            if (fileHeader.Characteristics & IMAGE_FILE_RELOCS_STRIPPED) {
                printf("Relocation info stripped from file; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_EXECUTABLE_IMAGE) {
                printf("File is executable; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_LINE_NUMS_STRIPPED) {
                printf("Line numbers stripped from file; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_LOCAL_SYMS_STRIPPED) {
                printf("Local symbols stripped from file; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_AGGRESIVE_WS_TRIM) {
                printf("Aggressively trim working set; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_LARGE_ADDRESS_AWARE) {
                printf("App can handle >2gb addresses; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_BYTES_REVERSED_LO) {
                printf("Bytes of machine word are reversed; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_32BIT_MACHINE) {
                printf("32 bit word machine; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_DEBUG_STRIPPED) {
                printf("Debugging info stripped from file in .DBG file; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP) {
                printf("If Image is on removable media, copy and run from the swap file; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_NET_RUN_FROM_SWAP) {
                printf("If Image is on Net, copy and run from the swap file; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_SYSTEM) {
                printf("System File; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_DLL) {
                printf("File is a DLL; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_UP_SYSTEM_ONLY) {
                printf("File should only be run on a UP machine; ");
            }

            if (fileHeader.Characteristics & IMAGE_FILE_BYTES_REVERSED_HI) {
                printf("Bytes of machine word are reversed; ");
            }
        }
    } // namespace win
} // namespace binfo
