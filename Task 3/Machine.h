//
// Created by at991 on 11/13/2023.
//

#ifndef A2_S23_20220013_PROBLEM10_CPP_MACHINE_H
#define A2_S23_20220013_PROBLEM10_CPP_MACHINE_H

#include <string>
#include <iostream>
#include "Registers.h"
#include "Memory.h"
#include "Instructions.h"

using namespace std;

class Machine : public Instructions{
private:
    string instructionRegister;
    int programCounter = 0;
public:

    void SetInstructionRegister(string val);
    void SetProgramCounter(int val);
    string GetInstructionRegister();
    void FetchNextInstruction();
    void executeInstruction(); // uncompleted
    int GetProgramCounter();

};


#endif //A2_S23_20220013_PROBLEM10_CPP_MACHINE_H
