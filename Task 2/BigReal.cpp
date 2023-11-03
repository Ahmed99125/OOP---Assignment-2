#include "BigReal.h"
#include <iostream>

BigReal::BigReal(double number) {
    if (!isValidReal(to_string(number))) {
        cout << "Enter a real number";
    }
    if (number < 0)
        sign = -1, number *= -1;
    else
        sign = 1;
    realNumber = to_string(number);
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
}

BigReal::BigReal(const BigReal &other) {
    if (other.realNumber[0] == '-')
        sign = -1;
    else
        sign = 1;
    realNumber = other.realNumber;
}

BigReal& BigReal::operator=(const BigReal &other) {
    this->realNumber = other.realNumber;
    if (other.realNumber[0] == '-')
        sign = -1;
    else
        sign = 1;
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

    string real[2], frac[2];
    int isReal{1};
    for (int i = 0; i < this->realNumber.size(); i++) {
        if (this->realNumber[i] == '.') {
            isReal = 0;
            continue;
        }
        if (isReal)
            real[0].push_back(this->realNumber[i]);
        else
            frac[0].push_back(this->realNumber[i]);
    }
    isReal = 1;
    for (int i = 0; i < other.realNumber.size(); i++) {
        if (other.realNumber[i] == '.') {
            isReal = 0;
            continue;
        }
        if (isReal)
            real[1].push_back(other.realNumber[i]);
        else
            frac[1].push_back(other.realNumber[i]);
    }

    // 1st Case
    if (this->sign > 0 && other.sign > 0) {
        // make sure the first string is the larger
        if (real[0].size() < real[1].size())
            swap(real[0], real[1]);
        if (frac[0].size() < frac[1].size())
            swap(frac[0], frac[1]);
        string newReal, newFrac;

    }
}














