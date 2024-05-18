// #define _CRT_SECURE_NO_WARNINGS
#include <binfo.hpp>
#include <cstdio>

#define REACHED_EOF             EOF
#define COULD_NOT_READ_ALL      -2
#define COULD_NOT_FSEEK0        -3
#define ERRMSG_COULD_NOT_FSEEK0 "Could not fseek to 0 after reading\n"

namespace binfo {

    /** return NULL on error */
    FILE *fopen(const char *_FileName, const char *_Mode) {
        FILE *file = std::fopen(_FileName, _Mode);

        if (file == NULL) {
            return NULL;
        }

        return file;
    }

    /** return non-zero on error */
    int fseek(FILE *_Stream, long _Offset, int _Origin) {
        int ok = std::fseek(_Stream, _Offset, _Origin);

        if (ok != 0) {
            return -1;
        }

        return 0;
    }

    /** return non-zero on error */
    int fread(void *_Buffer, size_t _ElementSize, size_t _ElementCount,
              FILE *_Stream) {
        size_t bytesRead =
            std::fread(_Buffer, _ElementSize, _ElementCount, _Stream);

        if (bytesRead != _ElementCount) {
            if (std::feof(_Stream)) {
                fprintf(stderr, "End of file reached\n");
                return REACHED_EOF;
            }

            if (std::ferror(_Stream)) {
                fprintf(stderr,
                        "Could not read all the requested bytes\n"
                        "Bytes read: %llu\n"
                        "Bytes requested: %llu\n",
                        bytesRead, _ElementCount);
                return COULD_NOT_READ_ALL;
            }
        }

        return 0;
    }

    /** return non-zero on error */
    int freadAndSeek0(void *_Buffer, size_t _ElementSize, size_t _ElementCount,
                      FILE *_Stream) {
        size_t bytesRead =
            std::fread(_Buffer, _ElementSize, _ElementCount, _Stream);

        if (bytesRead != _ElementCount) {
            if (std::feof(_Stream)) {
                return REACHED_EOF;
            }

            if (std::ferror(_Stream)) {
                printf("Could not read all the requested bytes\n"
                       "Bytes read: %llu\n"
                       "Bytes requested: %llu\n",
                       bytesRead, _ElementCount);
                return COULD_NOT_READ_ALL;
            }
        }

        if (binfo::fseek(_Stream, 0, SEEK_SET) != 0) {
            printf(ERRMSG_COULD_NOT_FSEEK0);
            return COULD_NOT_FSEEK0;
        }

        return 0;
    }

    // UTILS

    /** return non-zero on error */
    int openFile(const char *filename, FILE **file) {
        *file = binfo::fopen(filename, "rb");
        if (*file == NULL) {
            printf("Could not open file, check file name\n");
            return 1;
        }

        return 0;
    }
} // namespace binfo
