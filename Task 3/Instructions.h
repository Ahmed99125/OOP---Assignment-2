//
// Created by at991 on 11/13/2023.
//

#ifndef A2_S23_20220013_PROBLEM10_CPP_INSTRUCTIONS_H
#define A2_S23_20220013_PROBLEM10_CPP_INSTRUCTIONS_H
#include <iostream>
#include <string.h>
#include "Memory.h"
#include "Registers.h"
using namespace std;

class Instructions:  public Memory, public Registers {
private:

public:
    void Instruction1(string instruction);
};


#endif //A2_S23_20220013_PROBLEM10_CPP_INSTRUCTIONS_H
