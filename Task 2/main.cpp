#include <iostream>
#include "BigReal.h"

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