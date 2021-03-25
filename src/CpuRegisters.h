#ifndef INC_6502EMULATOR_CPUREGISTERS_H
#define INC_6502EMULATOR_CPUREGISTERS_H
#include "Shared.h"

namespace Emulator {
    struct DataRegs {
        u8 A, X, Y;
    };

    struct FlagsRegs {
        u8 Carry              : 1;
        u8 Zero               : 1;
        u8 InterruptDisable   : 1;
        u8 DecimalMode        : 1;
        u8 BreakCmd           : 1;
        u8 Overflow           : 1;
        u8 Negative           : 1;
    };

    struct Registers {
        DataRegs Data;
        FlagsRegs Flags;
    };
}

#endif //INC_6502EMULATOR_CPUREGISTERS_H
