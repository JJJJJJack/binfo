#include <BinaryManager.hpp>
#include <BinaryManagerElf32.hpp>
#include <BinaryManagerElf64.hpp>

#include <Executables.hpp>
#include <linuxstructs.h>

namespace binfo {
    namespace linux {
        int linuxBinfo(FILE *file) {
            Executables e;
            bool err = false;

            switch (binfo::linux::checkElfBitness(file)) {
                case 0:
                    printf("Invalid ELF class\n");
                    return 0;
                case ELFCLASS32:
                    e.elf32 = new BinaryManager<Elf32_Ehdr>(file, &err);
                    if (err) {
                        return 1;
                    }

                    e.elf32->showHeaderInfo();
                    return 0;
                case ELFCLASS64:
                    e.elf64 = new BinaryManager<Elf64_Ehdr>(file, &err);
                    if (err) {
                        return 1;
                    }

                    e.elf64->showHeaderInfo();
                    return 0;
                default:
                    printf("Unknown ELF class\n");
                    return 0;
            };

            return 0;
        }

        int checkElfBitness(FILE *file) {
            uint8_t bitness;

            if (binfo::fseek(file, 4, SEEK_SET) != 0) {
                printf("Could not seek to ELF header\n");
                return 1;
            }

            if (binfo::freadAndSeek0(&bitness, 1, 1, file) != 0) {
                printf("Could not read ELF header\n");
                return 1;
            }

            return bitness;
        }

        void elfPrintMachine(uint16_t machine) {
            switch (machine) {
                case EM_NONE:
                    printf("No machine ");
                    break;
                case EM_M32:
                    printf("AT&T WE 32100 ");
                    break;
                case EM_SPARC:
                    printf("SPARC ");
                    break;
                case EM_386:
                    printf("Intel 80386 ");
                    break;
                case EM_68K:
                    printf("Motorola 68000 ");
                    break;
                case EM_88K:
                    printf("Motorola 88000 ");
                    break;
                case EM_860:
                    printf("Intel 80860 ");
                    break;
                case EM_MIPS:
                    printf("MIPS I Architecture ");
                    break;
                case EM_S370:
                    printf("IBM System/370 Processor ");
                    break;
                case EM_MIPS_RS3_LE:
                    printf("MIPS RS3000 Little-endian ");
                    break;
                case EM_PARISC:
                    printf("Hewlett-Packard PA-RISC ");
                    break;
                case EM_VPP500:
                    printf("Fujitsu VPP500 ");
                    break;
                case EM_SPARC32PLUS:
                    printf("Enhanced instruction set SPARC ");
                    break;
                case EM_960:
                    printf("Intel 80960 ");
                    break;
                case EM_PPC:
                    printf("PowerPC ");
                    break;
                case EM_PPC64:
                    printf("64-bit PowerPC ");
                    break;
                case EM_S390:
                    printf("IBM System/390 Processor ");
                    break;
                case EM_V800:
                    printf("NEC V800 ");
                    break;
                case EM_FR20:
                    printf("Fujitsu FR20 ");
                    break;
                case EM_RH32:
                    printf("TRW RH-32 ");
                    break;
                case EM_RCE:
                    printf("Motorola RCE ");
                    break;
                case EM_ARM:
                    printf("ARM Little-Endian ");
                    break;
                case EM_ALPHA:
                    printf("Digital Alpha ");
                    break;
                case EM_SH:
                    printf("Hitachi SH ");
                    break;
                case EM_SPARCV9:
                    printf("SPARC Version 9 ");
                    break;
                case EM_TRICORE:
                    printf("Siemens TriCore embedded processor ");
                    break;
                case EM_ARC:
                    printf("Argonaut RISC Core ");
                    break;
                case EM_H8_300:
                    printf("Hitachi H8/300 ");
                    break;
                case EM_H8_300H:
                    printf("Hitachi H8/300H ");
                    break;
                case EM_H8S:
                    printf("Hitachi H8S ");
                    break;
                case EM_H8_500:
                    printf("Hitachi H8/500 ");
                    break;
                case EM_IA_64:
                    printf("Intel IA-64 processor architecture ");
                    break;
                case EM_MIPS_X:
                    printf("Stanford MIPS-X ");
                    break;
                case EM_COLDFIRE:
                    printf("Motorola ColdFire ");
                    break;
                case EM_68HC12:
                    printf("Motorola M68HC12 ");
                    break;
                case EM_MMA:
                    printf("Fujitsu MMA Multimedia Accelerator ");
                    break;
                case EM_PCP:
                    printf("Siemens PCP ");
                    break;
                case EM_NCPU:
                    printf("Sony nCPU embedded RISC processor ");
                    break;
                case EM_NDR1:
                    printf("Denso NDR1 microprocessor ");
                    break;
                case EM_STARCORE:
                    printf("Motorola Star*Core processor ");
                    break;
                case EM_ME16:
                    printf("Toyota ME16 processor ");
                    break;
                case EM_ST100:
                    printf("STMicroelectronics ST100 processor ");
                    break;
                case EM_TINYJ:
                    printf("TinyJ embedded processor ");
                    break;
                case EM_X86_64:
                    printf("AMD x86-64 architecture ");
                    break;
                case EM_PDSP:
                    printf("Sony DSP Processor ");
                    break;
                case EM_PDP10:
                    printf("Digital Equipment Corp. PDP-10 ");
                    break;
                case EM_PDP11:
                    printf("Digital Equipment Corp. PDP-11 ");
                    break;
                case EM_FX66:
                    printf("Siemens FX66 microcontroller ");
                    break;
                case EM_ST9PLUS:
                    printf("STMicroelectronics ST9+ 8/16 bit microcontroller ");
                    break;
                case EM_ST7:
                    printf("STMicroelectronics ST7 8-bit microcontroller ");
                    break;
                case EM_68HC16:
                    printf("Motorola MC68HC16 Microcontroller ");
                    break;
                case EM_68HC11:
                    printf("Motorola MC68HC11 Microcontroller ");
                    break;
                case EM_68HC08:
                    printf("Motorola MC68HC08 Microcontroller ");
                    break;
                case EM_68HC05:
                    printf("Motorola MC68HC05 Microcontroller ");
                    break;
                case EM_SVX:
                    printf("Silicon Graphics SVx ");
                    break;
                case EM_ST19:
                    printf("STMicroelectronics ST19 8-bit microcontroller ");
                    break;
                case EM_VAX:
                    printf("Digital VAX ");
                    break;
                case EM_CRIS:
                    printf("Axis Communications 32-bit embedded processor ");
                    break;
                case EM_JAVELIN:
                    printf("Infineon Technologies 32-bit embedded processor ");
                    break;
                case EM_FIREPATH:
                    printf("Element 14 64-bit DSP Processor ");
                    break;
                case EM_ZSP:
                    printf("LSI Logic 16-bit DSP Processor ");
                    break;
                case EM_MMIX:
                    printf("Donald Knuth's educational 64-bit processor ");
                    break;
                case EM_HUANY:
                    printf("Harvard University machine-independent object files ");
                    break;
                case EM_PRISM:
                    printf("SiTera Prism ");
                    break;
                case EM_AVR:
                    printf("Atmel AVR 8-bit microcontroller ");
                    break;
                case EM_FR30:
                    printf("Fujitsu FR30 ");
                    break;
                case EM_D10V:
                    printf("Mitsubishi D10V ");
                    break;
                case EM_D30V:
                    printf("Mitsubishi D30V ");
                    break;
                case EM_V850:
                    printf("NEC v850 ");
                    break;
                case EM_M32R:
                    printf("Mitsubishi M32R ");
                    break;
                case EM_MN10300:
                    printf("Matsushita MN10300 ");
                    break;
                case EM_MN10200:
                    printf("Matsushita MN10200 ");
                    break;
                case EM_PJ:
                    printf("picoJava ");
                    break;
                case EM_OPENRISC:
                    printf("OpenRISC 32-bit embedded processor ");
                    break;
                case EM_ARC_A5:
                    printf("ARC Cores Tangent-A5 ");
                    break;
                case EM_XTENSA:
                    printf("Tensilica Xtensa Architecture ");
                    break;
                case EM_VIDEOCORE:
                    printf("Alphamosaic VideoCore processor ");
                    break;
                case EM_TMM_GPP:
                    printf("Thompson Multimedia General Purpose Processor ");
                    break;
                case EM_NS32K:
                    printf("National Semiconductor 32000 series ");
                    break;
                case EM_TPC:
                    printf("Tenor Network TPC processor ");
                    break;
                case EM_SNP1K:
                    printf("Trebia SNP 1000 processor ");
                    break;
                case EM_ST200:
                    printf("STMicroelectronics ST200 microcontroller ");
                    break;
                default:
                    printf("Unknown machine type ");
            }
        }
    } // namespace linux
} // namespace binfo
