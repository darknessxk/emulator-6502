#ifndef INC_6502EMULATOR_OPCODESFUNCTIONS_H
#define INC_6502EMULATOR_OPCODESFUNCTIONS_H
#include "Shared.h"
#include "CpuFunctions.h"
#include "CpuRegisters.h"
#include "Memory.h"

namespace Emulator::OpCodes::Functions {
    static void NoOp(u32& Cycles, Emulator::Memory& mem, u16& PC, u16& SP, Registers& regs) { }

    namespace Load {
        namespace Accumulator {
            static void Immediate(u32& Cycles, Emulator::Memory& mem, u16& PC, u16& SP, Registers& regs) {
                u8 Value = CpuFunctions::NextByte(Cycles, mem, PC);

                regs.Data.A = Value;

                CpuFunctions::VerifyFlag_Zero(regs);
                CpuFunctions::VerifyFlag_Negative(regs);
            }

            static void ZeroPage(u32& Cycles, Emulator::Memory& mem, u16& PC, u16& SP, Registers& regs) {
                u8 Value = CpuFunctions::NextByte(Cycles, mem, PC);

                regs.Data.A = CpuFunctions::ReadByte(Cycles, Value, mem);

                CpuFunctions::VerifyFlag_Zero(regs);
                CpuFunctions::VerifyFlag_Negative(regs);
            }

            static void ZeroPageX(u32& Cycles, Emulator::Memory& mem, u16& PC, u16& SP, Registers& regs) {
                u8 Value = CpuFunctions::NextByte(Cycles, mem, PC);
                Value += regs.Data.X;
                Cycles--;
                regs.Data.A = CpuFunctions::ReadByte(Cycles, Value, mem);

                CpuFunctions::VerifyFlag_Zero(regs);
                CpuFunctions::VerifyFlag_Negative(regs);
            }
        }
    }
}

#endif //INC_6502EMULATOR_OPCODESFUNCTIONS_H
