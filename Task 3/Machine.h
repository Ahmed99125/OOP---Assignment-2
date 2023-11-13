//
// Created by at991 on 11/13/2023.
//

#ifndef A2_S23_20220013_PROBLEM10_CPP_MACHINE_H
#define A2_S23_20220013_PROBLEM10_CPP_MACHINE_H


class Machine {
private:
    Register aregister;
    memory memory;
    int instructionRegister;
    int programCounter;
public:
    void Machine();
    void SetInstructionRegister();
    void SetProgramCounter();
    void fetch();


};


#endif //A2_S23_20220013_PROBLEM10_CPP_MACHINE_H
