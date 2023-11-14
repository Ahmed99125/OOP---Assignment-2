#include <iostream>
#include <string>
#include "Machine.h"

using namespace std;
void display();

int main(){
    Machine machine;
    string filename;
    cout << "Please enter the name of the file:" << endl;
    cin >> filename;
    machine.GetInstructions(filename);
    int input = -1;
    while (input != 0) {
        display();
        cin >> input;
        switch (input) {
            case 1:
                cout<< "Please enter the name of the file:" << endl;
                cin >> filename;
                machine.GetInstructions(filename);
                break;
            case 2:
                machine.FetchNextInstruction();
                break;
            case 3:
                machine.PrintRegisters();
                break;
            case 4:
                cout<< machine.GetInstructionRegister();
                break;
            case 5:
                cout<< machine.GetProgramCounter();
                break;
            case 6:
                machine.PrintMemory();
                break;
            case 7:
                machine.PrintMemory();
                machine.PrintRegisters();
                cout<< machine.GetProgramCounter();
                cout<< machine.GetInstructionRegister();
                break;
            case 8:
                machine.PrintScreen();
                break;
            case 9:
                machine.ClearScreen();
                break;

            case 0:
                break;
        }

    }

}

void display() {
    cout << "1- Load a new instruction file:" << endl;
    cout << "2- Fitch next instruction and execute" << endl;
    cout << "3- Print Registers" << endl;
    cout << "4- Print Instruction register" << endl;
    cout << "5- Print Program counter" << endl;
    cout << "6- print memory"<< endl;
    cout << "7- Print All Information" << endl;
    cout << "8- Print screen" << endl;
    cout << "9- Clear screen" << endl;
    cout << "0- Exit" << endl;
}