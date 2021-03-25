#include "Memory.h"

Emulator::Memory::Memory() {
    Data = std::vector<u8>(MEMORY_LIMIT, 0);
}

void Emulator::Memory::Reset() {
    if (!Data.empty()) std::fill(Data.begin(), Data.end(), 0);
}

u8 Emulator::Memory::Read(u16 address) const {
    return Data.empty() ? 0 : Data.at(address);
}

void Emulator::Memory::Write(u16 startAddress, std::vector<u8> data) {
    Data.insert(Data.begin() + startAddress, data.begin(), data.end());
}
