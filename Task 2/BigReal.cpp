#include "BigReal.h"
#include <iostream>

void BigReal::initParts(string number) {
    int isReal{1};
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == '.') {
            isReal = 0;
            continue;
        }
        if (isReal)
            this->intPart.push_back(number[i]);
        else
            this->fracPart.push_back(number[i]);
    }
}

BigReal::BigReal(double number) {
    if (!isValidReal(to_string(number))) {
        cout << "Enter a real number";
    }
    if (number < 0)
        sign = -1, number *= -1;
    else
        sign = 1;
    realNumber = to_string(number);
    this->initParts(to_string(number));
}

BigReal::BigReal(string number) {
    if (!isValidReal(number)) {
        cout << "Enter a real number";
    }
    if (number[0] == '-')
        sign = -1, number.erase(0);
    else
        sign = 1;
    realNumber = number;
    this->initParts(number);
}

BigReal::BigReal(const BigReal &other) {
    if (other.realNumber[0] == '-')
        sign = -1;
    else
        sign = 1;
    realNumber = other.realNumber;
    this->initParts(this->realNumber);
}

BigReal& BigReal::operator=(const BigReal &other) {
    this->realNumber = other.realNumber;
    this->initParts(this->realNumber);
    if (other.realNumber[0] == '-')
        sign = -1;
    else
        sign = 1;

    return *this;
}

void BigReal::setNum(string number) {
    if (!isValidReal(number)) {
        cout << "Enter a real number";
    }
    if (number[0] == '-')
        number = number.substr(1, number.size()-1), sign = -1;
    else
        sign = 1;
    this->realNumber = number;
    this->initParts(this->realNumber);
}

int BigReal::size() {
    return realNumber.size();
}

int BigReal::isPositive() {
    return sign;
}

bool BigReal::isValidReal(string number) {
    int start = 0, dots = 0;

    if (number[start] == '-' || number[start] == '+')
        start++;

    for (int i = start; i < number.size(); i++) {
        if (number[i] == '.' && !dots) {
            dots++;
            continue;
        }
        if (number[i] < '0' || number[i] > '9')
            return false;
    }

    return true;
}

BigReal BigReal::operator+(BigReal &other) {
/*
 * 3 cases
 * pos pos
 * pos neg
 * neg neg
 * */

    // 1st Case
    
}














