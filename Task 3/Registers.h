#ifndef A2_S23_20220013_PROBLEM10_CPP_RIGESTERS_H
#define A2_S23_20220013_PROBLEM10_CPP_RIGESTERS_H

#include <string>

using  namespace std;

class Registers {
private:
    string registers[16];
public:
    void SetRegister(int address, string val);
    string GetRegister(int address);
};

#endif //A2_S23_20220013_PROBLEM10_CPP_RIGESTERS_H