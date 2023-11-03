#include <iostream>
#include "BigReal.h"

using namespace std;

int main() {
    string n = "15";
    BigReal num = string("50.23");
    BigReal num2 = num;
    num2 = num2 + BigReal(15.99);
    cout << num2;

    return 0;
}