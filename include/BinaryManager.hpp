#ifndef BinaryManager_hpp
#define BinaryManager_hpp

#include <cstdint>
#include <cstdio>

// class AbstractBinaryManager {
//   public:
//     ~AbstractBinaryManager()      = default;
//     virtual int showHeaderInfo()  = 0;
//     virtual void showFormatInfo() = 0;
// };

template<class T, class... V>
class BinaryManager {
  private:
    T header;
    // template struct for program datas?
    FILE *file;

    static void printMachine(uint16_t machine) {
        printf("printMachine: could not get machine value, unknown file struct\n");
    };

  public:
    BinaryManager(FILE *_file, bool *err);
    void showHeaderInfo();
    void showFormatInfo();
};

/**
 * TODO:
 * - DOS:
    Get the PE header
 * - ELF:
 *  Get the Program Header from .phdr
 *
 */

#endif
