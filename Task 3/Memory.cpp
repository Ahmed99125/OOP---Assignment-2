#include "Memory.h"
#include "fstream"

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
void Memory:: PrintMemory(){
    for(int  i= 0 ; i< 256; i++){
       cout << hex << i << "   " << memory[i]<< endl;
    }
}