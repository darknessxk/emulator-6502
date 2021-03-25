#include "CPU.h"

void Emulator::CPU::Reset(Emulator::Memory& mem) {
    ProgramCounter = 0xFFFC;
    StackPointer = 0xFF;

    Registers.Flags.DecimalMode =
    Registers.Flags.BreakCmd =
    Registers.Flags.Carry =
    Registers.Flags.InterruptDisable =
    Registers.Flags.Negative =
    Registers.Flags.Overflow =
    Registers.Flags.Zero = 0;

    Registers.Data.A =
    Registers.Data.X =
    Registers.Data.Y = 0;

    mem.Reset();
}

Emulator::CPU::CPU(Memory& mem) {
    Reset(mem);
}

void Emulator::CPU::Execute(Memory &mem) {
    u32 Cycles = 1;
    do {
        u8 Code = CpuFunctions::NextByte(Cycles, mem, ProgramCounter);

        if (OpCodes::List.contains(Code)) {
            auto OpCode = OpCodes::List.at(Code);
            Cycles += OpCode.Cycles;
            OpCode.Function(Cycles, mem, ProgramCounter, StackPointer, Registers);
        }
        else
        {

        }

        Cycles--;
    } while ( Cycles > 0 );
}
