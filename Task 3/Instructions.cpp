//
// Created by at991 on 11/13/2023.
//

#include "Instructions.h"

void Instructions:: Instruction1(string instruction){
    // convert the hex string to int
    int memoryAddress = stoul(instruction.substr(2,2), 0, 16);
    // convert the hex char to string
    int registerAddress =  (instruction[1] >= 'A') ? (instruction[1] - 'A' + 10) : (instruction[1] - '0');
    // put the data from the memory to the register
     SetRegister(registerAddress, getMemory(memoryAddress));
}

