#ifndef INC_6502EMULATOR_CPUFUNCTIONS_H
#define INC_6502EMULATOR_CPUFUNCTIONS_H
#include "Shared.h"
#include "CpuRegisters.h"
#include "Memory.h"

namespace Emulator::CpuFunctions {
    static u8 NextByte(u32 &Cycles, Emulator::Memory &mem, u16 &PC) {
        const auto addr = PC;
        PC++;
        Cycles--;
        return mem.Read(addr);
    }

    static u16 NextWord(u32 &Cycles, Emulator::Memory &mem, u16 &PC) {
        auto Data = NextByte(Cycles, mem, PC);
        Data |= NextByte(Cycles, mem, PC) << 8;

        return Data;
    }

    static u8 ReadByte(u32 &Cycles, u16 addr, Emulator::Memory &mem) {
        Cycles--;
        return mem.Read(addr);
    }

    static u16 ReadWord(u32 &Cycles, u16 addr, Emulator::Memory &mem) {
        Cycles--;
        return mem.Read(addr);
    }

    static void VerifyFlag_Zero(Registers& regs) {
        regs.Flags.Zero = regs.Data.A == 0;
    }

    static void VerifyFlag_Negative(Registers& regs) {
        regs.Flags.Negative = (regs.Data.A & 0x0b10000000) > 0;
    }
}

#endif //INC_6502EMULATOR_CPUFUNCTIONS_H
