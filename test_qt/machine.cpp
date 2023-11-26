#include "Machine.h"

void Machine::SetProgramCounter(int val) {
    programCounter = val;
}

void Machine::SetInstructionRegister(string val) {
    instructionRegister = val;
}

void Machine::SetRunning(bool run) {
    running = run;
}

string Machine::FetchNextInstruction() {
    if(!GetRunning()) return "the code is halted";
    string tmp = getMemory(programCounter) + getMemory(programCounter+1);
    if ((tmp[0] < '1' || tmp[0] > '5') && (tmp[0] != 'B' && tmp[0] != 'C')) {
        //cout << "This instruction is not valid." << endl;

        return "Not Valid!";
    }
    for (int i = 1; i < tmp.size(); i++) {
        if ((tmp[i] < '0' || tmp[i] > '9') && (tmp[i] < 'A' || tmp[i] > 'F')) {
           // cout << "This instruction is not valid." << endl;
            return "Not Valid!";
        }
    }
    instructionRegister = tmp;
    programCounter += 2;
    return executeInstruction();
}
string Machine:: executeInstruction(){
    switch (instructionRegister[0]) {
    case '1':
        Instruction1(instructionRegister);
        break;
    case '2':
        Instruction2(instructionRegister);
        break;
    case '3':
        Instruction3(instructionRegister);
        break;
    case '4':
        Instruction4(instructionRegister);
        break;
    case '5':
        Instruction5(instructionRegister);
        break;
    case 'B':
        programCounter = InstructionB(instructionRegister, programCounter);
        break;
    case 'C':
        InstructionC(instructionRegister);
        SetRunning(false);
        break;
    }
    return "Valid!";
}
string Machine::GetInstructionRegister(){
    return instructionRegister;
}
int Machine::GetProgramCounter(){
    return  programCounter;
}
bool Machine::GetRunning() {
    return running;
}
