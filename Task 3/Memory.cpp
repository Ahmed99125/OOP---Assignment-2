#include "Memory.h"

void Memory::setMemory(int address, int val) {
    memory[address] = val;
}

int Memory::getMemory(int address) {
    return memory[address];
}