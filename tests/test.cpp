// #include <BinaryManager.hpp>
// #include <binfo.hpp>
// #include <linuxstructs.h>
// #include <winstructs.h>
// #include <memory>

// int main(int argc, char **argv) {
//     uint32_t magicNumber;
//     FILE *file = nullptr;
//     std::unique_ptr<AbstractBinaryManager> binaryManager;
//     bool err = false;

//     if (argc != 2) {
//         printf("Usage: %s <file>\n", argv[0]);
//         return 0;
//     }

//     if (binfo::openFile(argv[1], &file)) {
//         return 1;
//     }

//     if (binfo::readMagicNumber(&magicNumber, file)) {
//         return 2;
//     }

//     if ((uint16_t)magicNumber == DOS_MAGIC) {
//         binaryManager = std::make_unique<BinaryManager<IMAGE_DOS_HEADER, IMAGE_NT_HEADERS32>>(file, &err);
//         if (err) {
//             return 3;
//         }

//         binaryManager->showHeaderInfo();
//         return 0;
//     }

//     if (magicNumber == ELF_MAGIC) {
//         switch (binfo::linux::checkElfBitness(&file)) {
//             case ELFCLASS32:
//                 binaryManager = std::make_unique<BinaryManager<Elf32_Ehdr>>(file, &err);
//                 if (err) {
//                     return 4;
//                 }

//                 binaryManager->showHeaderInfo();
//                 return 0;
//             case ELFCLASS64:
//                 binaryManager = std::make_unique<BinaryManager<Elf64_Ehdr>>(file, &err);
//                 if (err) {
//                     return 5;
//                 }

//                 binaryManager->showHeaderInfo();
//                 return 0;
//             case -1:
//                 return 3;
//             default:
//                 printf("Unknown ELF class\n");
//                 return 0;
//         };
//     }

//     printf("Unknown file magic number: %x\n", magicNumber);

//     return 0;
// }
