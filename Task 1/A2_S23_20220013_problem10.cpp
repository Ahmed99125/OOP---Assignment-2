// File: A2_S23_20220013_Problem01.cpp
// Purpose: .........
// Author: Ahmed tamer fathy
// Section: S23
// ID: 20220013
// TA: ........................
// Date: 26 Oct 2023

#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <map>

using namespace std;

int main() {
    wifstream inputFile("input.txt");
    wofstream outputFile("output.txt");
    wifstream listFile("list.txt");
    if (inputFile.fail() || outputFile.fail() || listFile.fail()) {
        cout << "something went wrong";
        return 1;
    }
    map <wstring, wstring> list;
    wstring key, value;
    while (listFile >> key >> value) {
        list[key] = value;
    }

    wstring word;
    while (inputFile >> word) {
        if (list.find(word) != list.end())
            outputFile << list[word] << L' ';
        else
            outputFile << word << L' ';
    }

    return 0;
}