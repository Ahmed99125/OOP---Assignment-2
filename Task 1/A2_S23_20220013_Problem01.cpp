// File: A2_S23_20220013_Problem01.cpp
// Purpose: .........
// Author: Ahmed tamer fathy
// Section: S23
// ID: 20220013
// TA: ........................
// Date: 26 Oct 2023

#include <iostream>

using namespace std;

char *corrected_sentence(char *sentence);

int main() {
    char sentence[100];

    for (int i = 0; i < 100; i++) {
        sentence[i] = '\0';
    }

    cin.getline(sentence, 100);

    char *result = corrected_sentence(sentence);

    cout << result << endl;

    delete[] result;

    return 0;
}

char *corrected_sentence(char sentence[]) {
    char *result = new char[100];

    for (int i = 0; i < 100; i++) {
        result[i] = '\0';
    }

    int i = 0;
    while (sentence[i] != '\0') {
        if (sentence[i] == ' ' && i > 0 && result[i-1] != ' ')
            result[i] = ' ';
        else
            result[i] = tolower(sentence[i]);
        i++;
    }
    result[0] = toupper(result[0]);
    return result;
}