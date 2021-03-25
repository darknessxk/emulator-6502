#ifndef INC_6502EMULATOR_OPCODES_H
#define INC_6502EMULATOR_OPCODES_H
#include "Shared.h"
#include "CpuRegisters.h"
#include "Memory.h"
#include "OpCodesFunctions.h"

namespace Emulator::OpCodes {

    struct OpCode {
        u8 Size;
        u8 Cycles;
        std::function<void(u32& Cycles, Emulator::Memory& mem, u16& PC, u16& SP, Registers& regs)> Function;
    };

    namespace Codes {
        namespace Load {
            namespace Accumulator {
                static constexpr u8 Immediate = 0xA9;
                static constexpr u8 ZeroPage  = 0xA5;
                static constexpr u8 ZeroPageX = 0xB5;
                static constexpr u8 Absolute  = 0xAD;
                static constexpr u8 AbsoluteX = 0xBD;
                static constexpr u8 AbsoluteY = 0xB9;
                static constexpr u8 IndirectX = 0xA1;
                static constexpr u8 IndirectY = 0xB1;
            }
        }

        namespace Codes {
            static constexpr u8 JSR = 0x20;
        }
    }

    static std::map<u8, OpCode> List {

            // Load Accumulator
            { Codes::Load::Accumulator::Immediate, { 0x2, 0x2, Functions::Load::Accumulator::Immediate }},
            { Codes::Load::Accumulator::ZeroPage, { 0x2, 0x3, Functions::Load::Accumulator::ZeroPage }},
            { Codes::Load::Accumulator::ZeroPageX, { 0x2, 0x4, Functions::Load::Accumulator::ZeroPageX }},
            { Codes::Load::Accumulator::Absolute, { 0x3, 0x4, Functions::NoOp }},
            { Codes::Load::Accumulator::AbsoluteX, { 0x3, 0x4, Functions::NoOp }},
            { Codes::Load::Accumulator::AbsoluteY, { 0x3, 0x4, Functions::NoOp }},
            { Codes::Load::Accumulator::IndirectX, { 0x2, 0x6, Functions::NoOp }},
            { Codes::Load::Accumulator::IndirectY, { 0x2, 0x5, Functions::NoOp }},

    };
}

#endif //INC_6502EMULATOR_OPCODES_H
