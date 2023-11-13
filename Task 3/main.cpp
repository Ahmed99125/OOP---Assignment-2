#include <iostream>
#include <string>
#include "Machine.h"

using namespace std;

int main(){
    Machine machine;
    string filename;
    cout << "Please enter the name of the file:" << endl;
    cin >> filename;
    machine.loadInstruction(filename);
    int input = -1;
    while (input != 0) {
        machine.display();
        cin >> input;
        switch (input) {

        }
    }
}