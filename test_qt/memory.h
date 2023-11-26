#ifndef A2_S23_20220013_PROBLEM10_CPP_MEMORY_H
#define A2_S23_20220013_PROBLEM10_CPP_MEMORY_H
#include "string"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Memory {
private:
    string memory[256];
public:
    Memory();
    void setMemory(int address, string val);
    string getMemory(int address);
    string GetInstructions(string fileName);
    string PrintMemory();
};

#endif //A2_S23_20220013_PROBLEM10_CPP_MEMORY_H
