cmake_minimum_required(VERSION 3.17)
project(6502emulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(6502emulator main.cpp CPU.cpp CPU.h Memory.cpp Memory.h Shared.h OpCodes.h CpuRegisters.h CpuFunctions.h Includes.h OpCodesFunctions.h)