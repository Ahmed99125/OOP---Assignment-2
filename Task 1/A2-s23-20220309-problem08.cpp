#include <iostream>
using namespace std;

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