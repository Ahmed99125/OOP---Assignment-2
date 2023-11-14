#include "Machine.h"

void Machine::SetProgramCounter(int val) {
    programCounter = val;
}

void Machine::SetInstructionRegister(string val) {
    instructionRegister = val;
}

void Machine::FetchNextInstruction() {
    string tmp = getMemory(programCounter) + getMemory(programCounter+1);
    if ((tmp[0] < '1' || tmp[0] > '5') && (tmp[0] != 'B' && tmp[0] != 'C')) {
        cout << "This instruction is not valid." << endl;
        return;
    }
    for (int i = 1; i < tmp.size(); i++) {
        if ((tmp[i] < '0' || tmp[i] > '9') && (tmp[i] < 'A' || tmp[i] > 'F')) {
            cout << "This instruction is not valid." << endl;
            return;
        }
    }
    instructionRegister = tmp;
    programCounter += 2;
    executeInstruction();
}
void Machine:: executeInstruction(){
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
            break;
        case 'B':
            break;
        case 'C':
            break;
    }
}
string Machine::GetInstructionRegister(){
    return instructionRegister;
}
int Machine::GetProgramCounter(){
    return  programCounter;
}
