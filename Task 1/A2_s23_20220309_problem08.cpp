#include <iostream>
using namespace std;
// File: A2_s23_20220309_problem08.cpp
// Purpose: .........
// Author: mohamed mostafa ali
// Section: S23
// ID: 20220309
// TA: mohamed talaat
// Date: 30 Oct 2023
void pattern(int n, int i) {
    if (n == 1) {
        for (int j = 0; j < i; j++) {
            cout << "  "; // Print spaces for indentation
        }
        cout << "*\n"; // Print a single asterisk
    } else {
        pattern(n / 2, i); // Recursive call for the top half

        for (int j = 0; j < i; j++) {
            cout << "  "; // Print spaces for indentation
        }

        for (int j = 0; j < n; j++) {
            cout << "* "; // Print asterisks
        }
        cout << endl;

        pattern(n / 2, i + n / 2); // Recursive call for the bottom half
    }
}

int main() {
    int n = 8;
    int i = 0;
    cin>> n;
    cin>> i;

    pattern(n, i);
    return 0;
}
