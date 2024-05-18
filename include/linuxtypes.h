#ifndef linuxtypes_h
#define linuxtypes_h

#include <cstdint>

/*
 * ELF definitions common to all 32-bit architectures.
 */

typedef uint32_t Elf32_Addr;
typedef uint16_t Elf32_Half;
typedef uint32_t Elf32_Off;
typedef int32_t Elf32_Sword;
typedef uint32_t Elf32_Word;
typedef uint64_t Elf32_Lword;

typedef Elf32_Word Elf32_Hashelt;

/* Non-standard class-dependent datatype used for abstraction. */
typedef Elf32_Word Elf32_Size;
typedef Elf32_Sword Elf32_Ssize;

/*
 * ELF definitions common to all 64-bit architectures.
 */

typedef uint64_t Elf64_Addr;
typedef uint16_t Elf64_Half;
typedef uint64_t Elf64_Off;
typedef int32_t Elf64_Sword;
typedef int64_t Elf64_Sxword;
typedef uint32_t Elf64_Word;
typedef uint64_t Elf64_Lword;
typedef uint64_t Elf64_Xword;

/*
 * Types of dynamic symbol hash table bucket and chain elements.
 *
 * This is inconsistent among 64 bit architectures, so a machine dependent
 * typedef is required.
 */

typedef Elf64_Word Elf64_Hashelt;

/* Non-standard class-dependent datatype used for abstraction. */
typedef Elf64_Xword Elf64_Size;
typedef Elf64_Sxword Elf64_Ssize;

#endif
