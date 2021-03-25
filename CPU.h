#ifndef INC_6502EMULATOR_CPU_H
#define INC_6502EMULATOR_CPU_H
#include "Shared.h"
#include "Includes.h"

namespace Emulator {
    class CPU {
    public:
        u16 ProgramCounter{};
        u16 StackPointer{};
        Emulator::Registers Registers;

        explicit CPU(Memory& mem);

        void Reset(Memory& mem);
        void Execute(Memory& mem);
    };
};


#endif //INC_6502EMULATOR_CPU_H
