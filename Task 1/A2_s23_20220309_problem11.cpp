#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
// File: A2_s23_20220309_problem11.cpp
// Purpose: .........
// Author: mohamed mostafa ali
// Section: S23
// ID: 20220309
// TA: mohamed talaat
// Date: 30 Oct 2023
using namespace std;

// Function to compare two files character by character
bool characterComparison(const string& file1, const string& file2) {
    ifstream f1(file1);
    ifstream f2(file2);

    if (!f1 || !f2) {
        cerr << "Failed to open one or both files." << endl;
        return false;
    }

    char char1, char2;
    int lineNum = 1, charNum = 1;
    string line1, line2;

    while (f1.get(char1) && f2.get(char2)) {
        line1 += char1;
        line2 += char2;

        if (char1 != char2) {
            cout << "Files are different. First difference at line " << lineNum << ", character " << charNum << ":" << endl;
            cout << "File 1: " << char1 << endl;
            cout << "File 2: " << char2 << endl;

            // Print the entire lines before and after the difference
            string  s1 , s2;
            getline(f1, s1);
            getline(f2,s2);
            cout << "File 1 Line " << lineNum << ": " << line1 << s1 << endl;
            cout << "File 2 Line " << lineNum << ": " << line2 << s2 << endl;

            return false;
        }

        if (char1 == '\n') {
            lineNum++;
            charNum = 0;
            line1.clear();
            line2.clear();
        }
        charNum++;
    }

    cout << "Files are identical." << endl;
    return true;
}



// Function to compare two files word by word
bool wordComparison(const string& file1, const string& file2) {
    ifstream f1(file1);
    ifstream f2(file2);

    if (!f1 || !f2) {
        cerr << "Failed to open one or both files." << endl;
        return false;
    }

    string word1, word2;
    int lineNum = 1, wordNum = 1;
    string s1, s2;
    while (true) {
        f1 >> word1;
        f2 >> word2;
        s1+= word1 + " ";
        s2+= word2+ " ";
        if (f1.fail() || f2.fail()) {
            if (!f1.fail() || !f2.fail()) {
                cout << "Files have different word counts." << endl;
            }
            break;
        }

        if (word1 != word2) {
            cout << "Files are different. First difference at line " << lineNum << ", word " << wordNum << ":" << endl;
            cout << "File 1: " << word1 << endl;
            cout << "File 2: " << word2 << endl;

            // Print the content of the lines where the difference occurred
            string line1, line2;
            getline(f1, line1);
            getline(f2, line2);
            cout << "File 1 Line " << lineNum << ": " <<s1<< line1 << endl;
            cout << "File 2 Line " << lineNum << ": " <<s2 << line2 << endl;

            return false;
        }
        char m;
        f1.get(m);
        if ( m == '\n' ) {
            lineNum++;
            wordNum = 1;
            s1.clear();
            s2.clear();
        } else {
            wordNum++;
        }
    }

    cout << "Files are identical." << endl;
    return true;
}

int main() {
    string file1, file2;
    int comparisonType;

    cout << "Enter the name of the first file: " << endl ;
    cin >> file1;
    cout << "Enter the name of the second file: " << endl;
    cin >> file2;

    cout << "Enter comparison type (1 for character-by-character, 2 for word-by-word): "<< endl;
    cin >> comparisonType;

    if (comparisonType == 1) {
        characterComparison(file1, file2);
    } else if (comparisonType == 2) {
        wordComparison(file1, file2);
    } else {
        cerr << "Invalid comparison type. Please enter 1 or 2." << endl;
    }

    return 0;
}
