#include "BigReal.h"
#include <iostream>

void BigReal::initParts(string number) {
    int isReal{1};

    if (number.size() > 0 && number[0] != '.')
        intPart.clear();

    for (int i = 0; i < number.size(); i++) {
        if (number[i] == '.') {
            fracPart.clear();
            isReal = 0;
            continue;
        }
        if (isReal)
            this->intPart.push_back(number[i]);
        else
            this->fracPart.push_back(number[i]);
    }
}

BigReal::BigReal()
: realNumber{"0.0"}, intPart{"0"}, fracPart{"0"}, sign{0} {

}

BigReal::BigReal(double number)
: realNumber{"0.0"}, intPart{"0"}, fracPart{"0"}, sign{0} {
    if (!isValidReal(to_string(number))) {
        cout << "Not valid input" << endl;
    }
    else {
        if (number < 0)
            sign = -1, number *= -1;
        else
            sign = 1;
        realNumber = to_string(number);
        this->initParts(to_string(number));
    }
}

BigReal::BigReal(string number)
: realNumber{"0.0"}, intPart{"0"}, fracPart{"0"}, sign{0} {
    if (!isValidReal(number)) {
        cout << "Not valid input" << endl;
    }
    else {
        if (number[0] == '-')
            sign = -1, number.erase(0);
        else
            sign = 1;
        realNumber = number;
        this->initParts(number);
    }
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

    BigReal res;

    // lambda function
    auto add = [] (string num1, string num2, int &r) -> string {
        string res;
        if (num1.size() < num2.size())
            swap(num1, num2);
        for (int i = num1.size()-1; i >= 0; i--) {
            int sum = num1[i]-'0' + r;
            if (i < num2.size())
                sum += num2[i]-'0';
            res.push_back((sum % 10)+'0');
            r = sum / 10;
        }
        for (int i = 0; i < res.size() / 2; i++)
            swap(res[i], res[res.size()-1-i]);
        return res;
    };

    // 1st Case
    if (this->sign > 0 && other.sign > 0) {
        int remainder = 0;
        res.fracPart = add(this->fracPart, other.fracPart, remainder);
        res.intPart = add(this->intPart, other.intPart, remainder);
        res.realNumber = res.intPart + "." + res.fracPart;
        return res;
    }
}

BigReal BigReal::operator+(BigReal &&other) {
/*
 * 3 cases
 * pos pos
 * pos neg
 * neg neg
 * */

    BigReal res;

    // lambda function
    auto add = [] (string num1, string num2, int &r) -> string {
        string res;
        if (num1.size() < num2.size())
            swap(num1, num2);
        for (int i = num1.size()-1; i >= 0; i--) {
            int sum = num1[i]-'0' + r;
            if (i < num2.size())
                sum += num2[i]-'0';
            res.push_back((sum % 10)+'0');
            r = sum / 10;
        }
        for (int i = 0; i < res.size() / 2; i++)
            swap(res[i], res[res.size()-1-i]);
        return res;
    };

    // 1st Case
    if (this->sign > 0 && other.sign > 0) {
        int remainder = 0;
        res.fracPart = add(this->fracPart, other.fracPart, remainder);
        res.intPart = add(this->intPart, other.intPart, remainder);
        res.realNumber = res.intPart + "." + res.fracPart;
        return res;
    }
}

ostream &operator<<(ostream &os, BigReal num) {
    if (num.sign < 0)
        os << '-';
    os << num.realNumber;
}












