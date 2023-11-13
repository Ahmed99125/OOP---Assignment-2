#ifndef A2_S23_20220013_PROBLEM10_CPP_MEMORY_H
#define A2_S23_20220013_PROBLEM10_CPP_MEMORY_H
#include "string"
using namespace std;

class Memory {
private:
    string memory[256];
public:
    void setMemory(int address, string val);
    void GetInstructions(string fileName);
    string getMemory(int address);
};

#endif //A2_S23_20220013_PROBLEM10_CPP_MEMORY_H