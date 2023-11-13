#ifndef A2_S23_20220013_PROBLEM10_CPP_RIGESTERS_H
#define A2_S23_20220013_PROBLEM10_CPP_RIGESTERS_H
using  namespace std;
class Registers {
private:
    int registers[16];
public:
    void SetRegister(int address, int val);
    int GetRegister(int address);
};

#endif //A2_S23_20220013_PROBLEM10_CPP_RIGESTERS_H