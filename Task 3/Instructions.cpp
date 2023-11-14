//
// Created by at991 on 11/13/2023.
//

#include "Instructions.h"

void Instructions::Instruction1(string instruction){
    // convert the hex string to int
    int memoryAddress = stoul(instruction.substr(2,2), 0, 16);
    // convert the hex char to string
    int registerAddress =  (instruction[1] >= 'A') ? (instruction[1] - 'A' + 10) : (instruction[1] - '0');
    // put the data from the memory to the register
     SetRegister(registerAddress, getMemory(memoryAddress));
}

void Instructions::Instruction2(string instruction) {
    // convert the hex string to int
    int value = stoul(instruction.substr(2,2), 0, 16);
    // convert the hex char to string
    int registerAddress =  (instruction[1] >= 'A') ? (instruction[1] - 'A' + 10) : (instruction[1] - '0');
    // put the data from the memory to the register
    SetRegister(registerAddress, to_string(value));
}

void Instructions::Instruction3(string instruction) {
    // convert the hex string to int
    int memoryAddress = stoul(instruction.substr(2,2), 0, 16);
    // convert the hex char to string
    int registerAddress =  (instruction[1] >= 'A') ? (instruction[1] - 'A' + 10) : (instruction[1] - '0');

    // if memmory address is 0 print to screen else save it in memory
    if (memoryAddress > 0) {
        setMemory(memoryAddress, GetRegister(registerAddress));
    }
    else {
        screen += GetRegister(registerAddress) + "\n";
        PrintScreen();
    }
}

void Instructions::Instruction4(string instruction) {
    // convert the hex string to int
    int firstRegister = (instruction[2] >= 'A') ? (instruction[2] - 'A' + 10) : (instruction[2] - '0');
    // convert the hex char to string
    int secondAddress =  (instruction[3] >= 'A') ? (instruction[3] - 'A' + 10) : (instruction[3] - '0');

    // move the value of the first register to the second register
    SetRegister(secondAddress, GetRegister(firstRegister));
}

void Instructions::Instruction5(string instruction) {
    // convert the hex string to int
    int firstRegister = (instruction[2] >= 'A') ? (instruction[2] - 'A' + 10) : (instruction[2] - '0');
    // convert the hex char to string
    int secondRegister =  (instruction[3] >= 'A') ? (instruction[3] - 'A' + 10) : (instruction[3] - '0');

    int thirdRegister = (instruction[1] >= 'A') ? (instruction[1] - 'A' + 10) : (instruction[1] - '0');
    int sum = stoi(GetRegister(firstRegister)) + stoi(GetRegister(secondRegister));
    SetRegister(thirdRegister, to_string(sum));
}

int Instructions::InstructionB(string instruction, int prCounter) {
    // convert the hex string to int
    int firstRegister = 0;
    // convert the hex char to string
    int secondRegister =  (instruction[1] >= 'A') ? (instruction[1] - 'A' + 10) : (instruction[1] - '0');
    if(GetRegister(firstRegister) == GetRegister(secondRegister)) {
        return stoul(instruction.substr(2,2), 0, 16);
    }
    return prCounter;
}

void Instructions::InstructionC(string instruction) {
    if(instruction == "C000") {
        PrintScreen();
    }
    
}

void Instructions::PrintScreen() {
    cout << screen << endl;
}

void Instructions::ClearScreen() {
    screen = "Screen:\n";
}