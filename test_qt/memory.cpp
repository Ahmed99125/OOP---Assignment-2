#include "Memory.h"
#include "fstream"

Memory::Memory() {
    for (int i = 0; i < 256; i++) {
        memory[i] = "00";
    }
}

void Memory::setMemory(int address, string val) {
    memory[address] = val;
}

string Memory::getMemory(int address) {
    return memory[address];
}

void Memory:: GetInstructions(string fileName){
    ifstream f1(fileName);
    string instruction;
    int counter = 0 ;
    while(getline(f1,instruction)){
        memory[counter] = instruction[0];
        memory[counter].push_back(instruction[2]);
        counter ++;
        memory[counter] = instruction[4];
        memory[counter].push_back(instruction[5]);
        counter++;
    }
}
string Memory:: PrintMemory(){
    string s;
    for(int  i= 0 ; i< 256; i++){
        stringstream s1;
        s1 << hex << i;
        s += s1.str() + "   " + memory[i] + "\n";
    }
    return s;
}
