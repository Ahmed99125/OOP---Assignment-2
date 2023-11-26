//
// Created by at991 on 11/13/2023.
//

#include "Registers.h"

Registers::Registers() {
    for (int i = 0; i < 16; i++) {
        registers[i] = "00";
    }
}

void Registers::SetRegister(int address, string val){
    registers[address] = val;
}

string Registers::GetRegister(int address){
    return registers[address];
}
string Registers:: PrintRegisters(){
    string s;
    for(int  i= 0 ; i< 16; i++){
        stringstream s1;
        s1 << hex << i;
        s += s1.str() + "   " + registers[i] + "\n";
    }
    return s;
}
