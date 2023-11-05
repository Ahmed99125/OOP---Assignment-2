#ifndef ASSIGNMENT_2_BIGREAL_H
#define ASSIGNMENT_2_BIGREAL_H

#include <string>
// File: BigReal.cpp
// Purpose: the header that had the prototype of the function and constructors of the class
// Author: Ahmed tamer fathy _ moahmed mostafa  ali _ Youssef Nasser Mohamed
// Section: S23
// ID: 20220013 _ 20220309 _ 20220416
// TA: mohamed talaat
// Date: 31 Oct 2023
using namespace std;

class BigReal {
    friend ostream& operator<<(ostream &os, const BigReal &num);
private:
    string realNumber, intPart, fracPart;
    int sign;
    bool isValidReal(string number);
    void initParts(string number);
public:
    BigReal();
    BigReal(double number);
    BigReal(string number);
    BigReal(const BigReal &other);
    BigReal &operator=(const BigReal &other);

    void setNum(string number);
    int size();
    int isPositive();

    BigReal operator+(BigReal &other);
    BigReal operator+(BigReal &&other);

    BigReal operator-(BigReal &other);
    BigReal operator-(BigReal &&other);

    int compMagnitude(const BigReal &num2) const;

    bool operator<(const BigReal &other) const;
    bool operator>(const BigReal &other) const;
    bool operator==(const BigReal &other) const;
};


#endif //ASSIGNMENT_2_BIGREAL_H
