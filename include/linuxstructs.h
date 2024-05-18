#ifndef linuxstructs_h
#define linuxstructs_h

#include <linuxtypes.h>

#define EI_NIDENT 16

/** e_ident[] Identification Indexes */
#define EI_MAG0       0
#define EI_MAG1       1
#define EI_MAG2       2
#define EI_MAG3       3
#define EI_CLASS      4
#define EI_DATA       5
#define EI_VERSION    6
#define EI_OSABI      7
#define EI_ABIVERSION 8
#define EI_PAD        9
#define EI_NIDENT     16

/** EI_CLASS values (e_ident[4]) */
#define ELFCLASSNONE 0
#define ELFCLASS32   1
#define ELFCLASS64   2

/*
 * ELF header.
 */

typedef struct {
    unsigned char e_ident[EI_NIDENT]; /* File identification. */
    Elf32_Half e_type;                /* File type. */
    Elf32_Half e_machine;             /* Machine architecture. */
    Elf32_Word e_version;             /* ELF format version. */
    Elf32_Addr e_entry;               /* Entry point. */
    Elf32_Off e_phoff;                /* Program header file offset. */
    Elf32_Off e_shoff;                /* Section header file offset. */
    Elf32_Word e_flags;               /* Architecture-specific flags. */
    Elf32_Half e_ehsize;              /* Size of ELF header in bytes. */
    Elf32_Half e_phentsize;           /* Size of program header entry. */
    Elf32_Half e_phnum;               /* Number of program header entries. */
    Elf32_Half e_shentsize;           /* Size of section header entry. */
    Elf32_Half e_shnum;               /* Number of section header entries. */
    Elf32_Half e_shstrndx;            /* Section name strings section. */
} Elf32_Ehdr;

/*
 * Section header.
 */

typedef struct {
    Elf32_Word sh_name;      /* Section name (index into the
                        section header string table). */
    Elf32_Word sh_type;      /* Section type. */
    Elf32_Word sh_flags;     /* Section flags. */
    Elf32_Addr sh_addr;      /* Address in memory image. */
    Elf32_Off sh_offset;     /* Offset in file. */
    Elf32_Word sh_size;      /* Size in bytes. */
    Elf32_Word sh_link;      /* Index of a related section. */
    Elf32_Word sh_info;      /* Depends on section type. */
    Elf32_Word sh_addralign; /* Alignment in bytes. */
    Elf32_Word sh_entsize;   /* Size of each entry in section. */
} Elf32_Shdr;

/*
 * Program header.
 */

typedef struct {
    Elf32_Word p_type;   /* Entry type. */
    Elf32_Off p_offset;  /* File offset of contents. */
    Elf32_Addr p_vaddr;  /* Virtual address in memory image. */
    Elf32_Addr p_paddr;  /* Physical address (not used). */
    Elf32_Word p_filesz; /* Size of contents in file. */
    Elf32_Word p_memsz;  /* Size of contents in memory. */
    Elf32_Word p_flags;  /* Access permission flags. */
    Elf32_Word p_align;  /* Alignment in memory and file. */
} Elf32_Phdr;

/*
 * ELF header.
 */

typedef struct {
    unsigned char e_ident[EI_NIDENT]; /* File identification. */
    Elf64_Half e_type;                /* File type. */
    Elf64_Half e_machine;             /* Machine architecture. */
    Elf64_Word e_version;             /* ELF format version. */
    Elf64_Addr e_entry;               /* Entry point. */
    Elf64_Off e_phoff;                /* Program header file offset. */
    Elf64_Off e_shoff;                /* Section header file offset. */
    Elf64_Word e_flags;               /* Architecture-specific flags. */
    Elf64_Half e_ehsize;              /* Size of ELF header in bytes. */
    Elf64_Half e_phentsize;           /* Size of program header entry. */
    Elf64_Half e_phnum;               /* Number of program header entries. */
    Elf64_Half e_shentsize;           /* Size of section header entry. */
    Elf64_Half e_shnum;               /* Number of section header entries. */
    Elf64_Half e_shstrndx;            /* Section name strings section. */
} Elf64_Ehdr;

/*
 * Section header.
 */

typedef struct {
    Elf64_Word sh_name;       /* Section name (index into the
                         section header string table). */
    Elf64_Word sh_type;       /* Section type. */
    Elf64_Xword sh_flags;     /* Section flags. */
    Elf64_Addr sh_addr;       /* Address in memory image. */
    Elf64_Off sh_offset;      /* Offset in file. */
    Elf64_Xword sh_size;      /* Size in bytes. */
    Elf64_Word sh_link;       /* Index of a related section. */
    Elf64_Word sh_info;       /* Depends on section type. */
    Elf64_Xword sh_addralign; /* Alignment in bytes. */
    Elf64_Xword sh_entsize;   /* Size of each entry in section. */
} Elf64_Shdr;

/*
 * Program header.
 */

typedef struct {
    Elf64_Word p_type;    /* Entry type. */
    Elf64_Word p_flags;   /* Access permission flags. */
    Elf64_Off p_offset;   /* File offset of contents. */
    Elf64_Addr p_vaddr;   /* Virtual address in memory image. */
    Elf64_Addr p_paddr;   /* Physical address (not used). */
    Elf64_Xword p_filesz; /* Size of contents in file. */
    Elf64_Xword p_memsz;  /* Size of contents in memory. */
    Elf64_Xword p_align;  /* Alignment in memory and file. */
} Elf64_Phdr;

#define EM_NONE  0 //	No machine
#define EM_M32   1 //	AT&T WE 32100
#define EM_SPARC 2 //	SPARC
#define EM_386   3 //	Intel 80386
#define EM_68K   4 //	Motorola 68000
#define EM_88K   5 //	Motorola 88000
// 6	Reserved for future use (was EM_486)
#define EM_860         7  //	Intel 80860
#define EM_MIPS        8  //	MIPS I Architecture
#define EM_S370        9  //	IBM System/370 Processor
#define EM_MIPS_RS3_LE 10 //	MIPS RS3000 Little-endian
// 11-14	Reserved for future use
#define EM_PARISC 15 //	Hewlett-Packard PA-RISC
// 16	Reserved for future use
#define EM_VPP500      17 //	Fujitsu VPP500
#define EM_SPARC32PLUS 18 //	Enhanced instruction set SPARC
#define EM_960         19 //	Intel 80960
#define EM_PPC         20 //	PowerPC
#define EM_PPC64       21 //	64-bit PowerPC
#define EM_S390        22 //	IBM System/390 Processor
// 23-35	Reserved for future use
#define EM_V800      36  //	NEC V800
#define EM_FR20      37  //	Fujitsu FR20
#define EM_RH32      38  //	TRW RH-32
#define EM_RCE       39  //	Motorola RCE
#define EM_ARM       40  //	Advanced RISC Machines ARM
#define EM_ALPHA     41  //	Digital Alpha
#define EM_SH        42  //	Hitachi SH
#define EM_SPARCV9   43  //	SPARC Version 9
#define EM_TRICORE   44  //	Siemens TriCore embedded processor
#define EM_ARC       45  //	Argonaut RISC Core, Argonaut Technologies Inc.
#define EM_H8_300    46  //	Hitachi H8/300
#define EM_H8_300H   47  //	Hitachi H8/300H
#define EM_H8S       48  //	Hitachi H8S
#define EM_H8_500    49  //	Hitachi H8/500
#define EM_IA_64     50  //	Intel IA-64 processor architecture
#define EM_MIPS_X    51  //	Stanford MIPS-X
#define EM_COLDFIRE  52  //	Motorola ColdFire
#define EM_68HC12    53  //	Motorola M68HC12
#define EM_MMA       54  //	Fujitsu MMA Multimedia Accelerator
#define EM_PCP       55  //	Siemens PCP
#define EM_NCPU      56  //	Sony nCPU embedded RISC processor
#define EM_NDR1      57  //	Denso NDR1 microprocessor
#define EM_STARCORE  58  //	Motorola Star*Core processor
#define EM_ME16      59  //	Toyota ME16 processor
#define EM_ST100     60  //	STMicroelectronics ST100 processor
#define EM_TINYJ     61  //	Advanced Logic Corp. TinyJ embedded processor family
#define EM_X86_64    62  //	AMD x86-64 architecture
#define EM_PDSP      63  //	Sony DSP Processor
#define EM_PDP10     64  //	Digital Equipment Corp. PDP-10
#define EM_PDP11     65  //	Digital Equipment Corp. PDP-11
#define EM_FX66      66  //	Siemens FX66 microcontroller
#define EM_ST9PLUS   67  //	STMicroelectronics ST9+ 8/16 bit microcontroller
#define EM_ST7       68  //	STMicroelectronics ST7 8-bit microcontroller
#define EM_68HC16    69  //	Motorola MC68HC16 Microcontroller
#define EM_68HC11    70  //	Motorola MC68HC11 Microcontroller
#define EM_68HC08    71  //	Motorola MC68HC08 Microcontroller
#define EM_68HC05    72  //	Motorola MC68HC05 Microcontroller
#define EM_SVX       73  //	Silicon Graphics SVx
#define EM_ST19      74  //	STMicroelectronics ST19 8-bit microcontroller
#define EM_VAX       75  //	Digital VAX
#define EM_CRIS      76  //	Axis Communications 32-bit embedded processor
#define EM_JAVELIN   77  //	Infineon Technologies 32-bit embedded processor
#define EM_FIREPATH  78  //	Element 14 64-bit DSP Processor
#define EM_ZSP       79  //	LSI Logic 16-bit DSP Processor
#define EM_MMIX      80  //	Donald Knuth's educational 64-bit processor
#define EM_HUANY     81  //	Harvard University machine-independent object files
#define EM_PRISM     82  //	SiTera Prism
#define EM_AVR       83  //	Atmel AVR 8-bit microcontroller
#define EM_FR30      84  //	Fujitsu FR30
#define EM_D10V      85  //	Mitsubishi D10V
#define EM_D30V      86  //	Mitsubishi D30V
#define EM_V850      87  //	NEC v850
#define EM_M32R      88  //	Mitsubishi M32R
#define EM_MN10300   89  //	Matsushita MN10300
#define EM_MN10200   90  //	Matsushita MN10200
#define EM_PJ        91  //	picoJava
#define EM_OPENRISC  92  //	OpenRISC 32-bit embedded processor
#define EM_ARC_A5    93  //	ARC Cores Tangent-A5
#define EM_XTENSA    94  //	Tensilica Xtensa Architecture
#define EM_VIDEOCORE 95  //	Alphamosaic VideoCore processor
#define EM_TMM_GPP   96  //	Thompson Multimedia General Purpose Processor
#define EM_NS32K     97  //	National Semiconductor 32000 series
#define EM_TPC       98  //	Tenor Network TPC processor
#define EM_SNP1K     99  //	Trebia SNP 1000 processor
#define EM_ST200     100 //	STMicroelectronics (www.st.com) ST200 microcontroller

#endif
