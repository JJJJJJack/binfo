#include <binfo.hpp>
#include <cstdio>

int main(int argc, char **argv) {
    FILE *file = nullptr;
    uint32_t magicNumber;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 0;
    }

    if (0 != binfo::openFile(argv[1], &file)) {
        return 1;
    }

    if (0 != binfo::freadAndSeek0(&magicNumber, 1, 4, file)) {
        return 1;
    }

#define DOS_MAGIC 0x5A4D
#define ELF_MAGIC 0x464C457F

    if ((uint16_t)magicNumber == DOS_MAGIC) {
        if (binfo::win::winBinfo(file) != 0) {
            if (fclose(file) != 0) {
                printf("Coud not close file\n");
            }

            return 1;
        }

        if (fclose(file) != 0) {
            printf("Coud not close file\n");
            return 1;
        }

        return 0;
    }

    if (magicNumber == ELF_MAGIC) {
        if (binfo::linuxNs::linuxBinfo(file) != 0) {
            if (fclose(file) != 0) {
                printf("Coud not close file\n");
            }

            return 1;
        }

        if (fclose(file) != 0) {
            printf("Coud not close file\n");

            return 1;
        }

        return 0;
    }

    printf("Unknown %x file magic number\n", magicNumber);

    return 0;
}
