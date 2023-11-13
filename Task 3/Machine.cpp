#include "Machine.h"

void Machine::SetProgramCounter(int val) {
    programCounter = val;
}

void Machine::SetInstructionRegister(string val) {
    instructionRegister = val;
}

void Machine::FetchNextInstruction() {
    string tmp = memory.getMemory(programCounter) + memory.getMemory(programCounter+1);
    if ((tmp[0] < '1' || tmp[0] > '5') && (tmp[0] != 'B' && tmp[0] != 'C')) {
        cout << "This instruction is not valid." << endl;
        return;
    }
    for (int i = 1; i < tmp.size(); i++) {
        if ((tmp[i] < '0' || tmp[i] > '9') && (tmp[i] < 'A' || tmp[i] > 'F')) {
            cout << "This instruction is not valid." << endl;
            return;
        }
        executeInstruction();
    }
    instructionRegister = tmp;
    programCounter += 2;
}

void Machine::display() {
    cout << "1- Load new instruction file:" << endl;
    cout << "2- Fitch next instruction and execute" << endl;
    cout << "3- Print Registers" << endl;
    cout << "4- Print Instruction register" << endl;
    cout << "5- Print Program counter" << endl;
    cout << "6- Print All Information" << endl;
    cout << "0- Exit" << endl;
}

void Machine::loadInstruction(string fileName) {
    memory.GetInstructions(fileName);
}