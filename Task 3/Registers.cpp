//
// Created by at991 on 11/13/2023.
//

#include "Registers.h"

void Registers::SetRegister(int address, int val){
    registers[address] = val;
}

int Registers::GetRegister(int address){
    return registers[address];
}