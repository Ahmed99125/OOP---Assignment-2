//
// Created by at991 on 11/13/2023.
//

#ifndef A2_S23_20220013_PROBLEM10_CPP_MACHINE_H
#define A2_S23_20220013_PROBLEM10_CPP_MACHINE_H

#include <string>
#include <iostream>
#include "Registers.h"
#include "Memory.h"

using namespace std;

class Machine {
private:
    Registers registers;
    Memory memory;
    string instructionRegister;
    int programCounter = 0;
public:
    void display();
    void SetInstructionRegister(string val);
    void SetProgramCounter(int val);
    void FetchNextInstruction();
    void executeInstruction(); // uncompleted
    void loadInstruction(string fileName);
};


#endif //A2_S23_20220013_PROBLEM10_CPP_MACHINE_H
