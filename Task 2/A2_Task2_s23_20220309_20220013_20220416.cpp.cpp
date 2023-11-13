#include <iostream>
#include "BigReal.h"

// File: BigReal.cpp
// Purpose: the main function for testing the class
// Author: Ahmed tamer fathy _ moahmed mostafa  ali _ Youssef Nasser Mohamed
// Section: S23
// ID: 20220013 _ 20220309 _ 20220416
// TA: mohamed talaat
// Date: 31 Oct 2023

using namespace std;

int main() {
    string n = "15";
    BigReal num = string("9");
    BigReal num2 = num;
    num2 = BigReal(9) + num2;
    if (num2 > num)
        cout << "yes";
    else cout << "no";

    return 0;
}