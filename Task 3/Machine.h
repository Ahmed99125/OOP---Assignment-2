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
    bool running = true;
public:

    void SetInstructionRegister(string val);
    void SetProgramCounter(int val);
    void SetRunning(bool run);
    string GetInstructionRegister();
    void FetchNextInstruction();
    void executeInstruction(); // uncompleted
    int GetProgramCounter();
    bool GetRunning();
};


#endif //A2_S23_20220013_PROBLEM10_CPP_MACHINE_H
