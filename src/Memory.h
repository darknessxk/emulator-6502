#ifndef INC_6502EMULATOR_MEMORY_H
#define INC_6502EMULATOR_MEMORY_H
#include "Shared.h"

namespace Emulator {
    constexpr u16 MEMORY_LIMIT = USHRT_MAX;

    class Memory {
    private:
        std::vector<u8> Data;
    public:
        [[nodiscard]] u8 Read(u16 address) const;
        void Write(u16 startAddress, std::vector<u8> data);

        Memory();
        void Reset();
    };
}


#endif //INC_6502EMULATOR_MEMORY_H
