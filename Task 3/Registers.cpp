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
void Registers:: PrintRegisters(){
    for(int  i= 0 ; i< 16; i++){
        cout << hex << i << "   " << registers[i]<< endl;

    }
}