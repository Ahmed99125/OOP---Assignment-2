//
// Created by at991 on 11/13/2023.
//

#include "Registers.h"

void Registers::SetRegister(int address, string val){
    registers[address] = val;
}

string Registers::GetRegister(int address){
    return registers[address];
}