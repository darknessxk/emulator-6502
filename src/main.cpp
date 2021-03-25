#include <iostream>
#include "Includes.h"

// Based into: obelisk.me.uk/6502
// This is a study only project!

int main() {
    Emulator::Memory mem{};
    auto* cpu = new Emulator::CPU(mem);

    mem.Write(0xFFFC, { 0xA9, 0x42 });

    cpu->Execute(mem);

    return 0;
}
