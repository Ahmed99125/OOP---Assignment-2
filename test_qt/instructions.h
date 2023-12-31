//
// Created by at991 on 11/13/2023.
//

#ifndef A2_S23_20220013_PROBLEM10_CPP_INSTRUCTIONS_H
#define A2_S23_20220013_PROBLEM10_CPP_INSTRUCTIONS_H
#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
#include "Memory.h"
#include "Registers.h"
using namespace std;

class Instructions:  public Memory, public Registers {
private:
    string screen ;
public:
    void Instruction1(string instruction);
    void Instruction2(string instruction);
    void Instruction3(string instruction);
    void Instruction4(string instruction);
    void Instruction5(string instruction);
    int InstructionB(string instruction, int prCounter);
    void InstructionC(string instruction);
    string PrintScreen();
    void ClearScreen();
};


#endif //A2_S23_20220013_PROBLEM10_CPP_INSTRUCTIONS_H
