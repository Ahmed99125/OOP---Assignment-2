#ifndef A2_S23_20220013_PROBLEM10_CPP_MEMORY_H
#define A2_S23_20220013_PROBLEM10_CPP_MEMORY_H

using namespace std;

class Memory {
private:
    int memory[256];
public:
    void setMemory(int address, int val);

    int getMemory(int address);
};

#endif //A2_S23_20220013_PROBLEM10_CPP_MEMORY_H