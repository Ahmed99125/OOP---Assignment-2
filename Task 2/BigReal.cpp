#include "BigReal.h"
#include <iostream>
// File: BigReal.cpp
// Purpose: the implementation of the class
// Author: Ahmed tamer fathy _ moahmed mostafa  ali _ Youssef Nasser Mohamed
// Section: S23
// ID: 20220013 _ 20220309 _ 20220416
// TA: mohamed talaat
// Date: 31 Oct 2023



// takes the number and breaks it to integer and fraction
void BigReal::initParts(string number) {
    bool isReal{1};

    if (number.size() > 0 && number[0] != '.')
        intPart.clear();

    for (int i = 0; i < number.size(); i++) {
        // check if we finished the integer part
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

// default constructor
BigReal::BigReal()
: realNumber{"0.0"}, intPart{"0"}, fracPart{"0"}, sign{0} {

}

// constructor
BigReal::BigReal(double number)
: realNumber{"0.0"}, intPart{"0"}, fracPart{"0"}, sign{0} {
    // check if the number is valid
    if (!isValidReal(to_string(number))) {
        cout << "Not valid input" << endl;
    }
    else {
        // initiating sign
        if (number < 0)
            sign = -1, number *= -1;
        else
            sign = 1;
        realNumber = to_string(number);
        this->initParts(to_string(number));

        // remove leading zeros
        int cnt = 0;
        for (int i = 0; i < intPart.size() / 2; i++) {
            if (intPart[i] != '0')
                break;
            cnt++;
        }
        intPart = intPart.substr(cnt, intPart.size() - cnt);

        realNumber = intPart + "." + fracPart;
    }
}

// constructor
BigReal::BigReal(string number)
: realNumber{"0.0"}, intPart{"0"}, fracPart{"0"}, sign{0} {
    // check if the number is valid
    if (!isValidReal(number)) {
        cout << "Not valid input" << endl;
    }
    else {
        // initiating sign
        if (number[0] == '-')
            sign = -1, number = number.substr(1, number.size()-1);
        else
            sign = 1;
        realNumber = number;
        this->initParts(number);

        // remove leading zeros
        int cnt = 0;
        for (int i = 0; i < intPart.size() / 2; i++) {
            if (intPart[i] != '0')
                break;
            cnt++;
        }
        intPart = intPart.substr(cnt, intPart.size() - cnt);

        realNumber = intPart + "." + fracPart;
    }
}

// copy constructor
BigReal::BigReal(const BigReal &other) {
    realNumber = other.realNumber;
    sign = other.sign;
    this->initParts(this->realNumber);
}

// assignment overload
BigReal& BigReal::operator=(const BigReal &other) {
    this->realNumber = other.realNumber;
    sign = other.sign;
    this->initParts(this->realNumber);

    return *this;
}

// setter for the number
void BigReal::setNum(string number) {
    if (!isValidReal(number)) {
        cout << "Enter a real number";
    }
    else {
        if (number[0] == '-')
            number = number.substr(1, number.size()-1), sign = -1;
        else
            sign = 1;
        this->realNumber = number;
        this->initParts(this->realNumber);

        // remove leading zeros
        int cnt = 0;
        for (int i = 0; i < intPart.size() / 2; i++) {
            if (intPart[i] != '0')
                break;
            cnt++;
        }
        intPart = intPart.substr(cnt, intPart.size() - cnt);

        realNumber = intPart + "." + fracPart;
    }
}

// return size
int BigReal::size() {
    return realNumber.size();
}

// return sign
int BigReal::isPositive() {
    return sign;
}

// check validity
bool BigReal::isValidReal(string number) {
    // dots is a counter of number of dots
    int start = 0, dots = 0;

    // sign checking
    if (number[start] == '-' || number[start] == '+')
        start++;

    for (int i = start; i < number.size(); i++) {
        if (number[i] == '.' && !dots) {
            dots++;
            continue;
        }
        // if the character is not a number return false
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

    // lambda functions
    auto add = [] (string num1, string num2, int &r, bool isInt) -> string {
        string res;
        if (num1.size() < num2.size())
            swap(num1, num2);
        if (num1.size() != num2.size()) {
            string tmp((num1.size() - num2.size()), '0');
            num2 = (isInt) ? tmp + num2 : num2 + tmp;
        }

        for (int i = num1.size()-1; i >= 0; i--) {
            int sum = num1[i]-'0' + num2[i]-'0' + r;
            res.push_back((sum % 10)+'0');
            r = sum / 10;
        }

        for (int i = 0; i < res.size() / 2; i++)
            swap(res[i], res[res.size()-1-i]);

        if (res == "")
            res = "0";
        return res;
    };

    auto subtract = [] (string num1, string num2, int &r, bool isInt) -> string {
        string res;

        // equaling size of strings
        if (num1.size() > num2.size()) {
            string tmp((num1.size() - num2.size()), '0');
            num2 = (isInt) ? tmp + num2 : num2 + tmp;
        }
        else if (num1.size() < num2.size()) {
            string tmp(num2.size() - num1.size(), '0');
            num1 = (isInt) ? tmp + num1 : num1 + tmp;
        }

        for (int i = num1.size()-1; i >= 0; i--) {
            int val1 = num1[i]-'0', val2 = num2[i]-'0';
            // checking remainder
            // if remainder is greater than 0
            if (r > 0) {
                if (val1 > 0) {
                    val1 -= 1;
                    r = 0;
                }
                else
                    val1 = 9;
            }

            if (val1 < val2) {
                val1 += 10;
                r = 1;
            }
            res.push_back((val1 - val2) + '0');
        }

        for (int i = 0; i < res.size() / 2; i++)
            swap(res[i], res[res.size()-1-i]);

        // remove leading zeros
        int cnt = 0;
        for (int i = 0; i < res.size() / 2; i++) {
            if (res[i] != '0')
                break;
            cnt++;
        }
        res = res.substr(cnt, res.size() - cnt);

        if (res == "")
            res = "0";
        return res;
    };

    // 1st and 3rd Case
    if (this->sign == other.sign) {
        int remainder = 0;
        // sending the remainder by reference
        res.fracPart = add(this->fracPart, other.fracPart, remainder, 0);
        res.intPart = add(this->intPart, other.intPart, remainder, 1);
        // check if there is still a remainder we did not use
        if (remainder > 0)
            res.intPart = "1" + res.intPart;
        res.realNumber = res.intPart + "." + res.fracPart;
        res.sign = this->sign;
    }

    // 2nd Case
    else if (this->sign != other.sign) {
        int remainder = 0;
        if (this->compMagnitude(other) >= 0) {
            res.fracPart = subtract(this->fracPart, other.fracPart, remainder, 0);
            res.intPart = subtract(this->intPart, other.intPart, remainder, 1);
            res.realNumber = res.intPart + "." + res.fracPart;
            res.sign = this->sign;
        }
        else {
            res.fracPart = subtract(other.fracPart, this->fracPart, remainder, 0);
            res.intPart = subtract(other.intPart, this->intPart, remainder, 1);
            res.realNumber = res.intPart + "." + res.fracPart;
            res.sign = other.sign;
        }
    }

    return res;
}

// same function but for rhs
BigReal BigReal::operator+(BigReal &&other) {
/*
 * 3 cases
 * pos pos
 * pos neg
 * neg neg
 * */

    BigReal res;

    // lambda functions
    auto add = [] (string num1, string num2, int &r, bool isInt) -> string {
        string res;
        if (num1.size() < num2.size())
            swap(num1, num2);
        if (num1.size() != num2.size()) {
            string tmp((num1.size() - num2.size()), '0');
            num2 = (isInt) ? tmp + num2 : num2 + tmp;
        }
        for (int i = num1.size()-1; i >= 0; i--) {
            int sum = num1[i]-'0' + num2[i]-'0' + r;
            res.push_back((sum % 10)+'0');
            r = sum / 10;
        }
        for (int i = 0; i < res.size() / 2; i++)
            swap(res[i], res[res.size()-1-i]);
        if (res == "")
            res = "0";
        return res;
    };

    auto subtract = [] (string num1, string num2, int &r, bool isInt) -> string {
        string res;

        // equaling size of strings
        if (num1.size() > num2.size()) {
            string tmp((num1.size() - num2.size()), '0');
            num2 = (isInt) ? tmp + num2 : num2 + tmp;
        }
        else if (num1.size() < num2.size()) {
            string tmp(num2.size() - num1.size(), '0');
            num1 = (isInt) ? tmp + num1 : num1 + tmp;
        }

        for (int i = num1.size()-1; i >= 0; i--) {
            int val1 = num1[i]-'0', val2 = num2[i]-'0';
            // checking remainder
            if (r > 0) {
                if (val1 > 0) {
                    val1 -= 1;
                    r = 0;
                }
                else
                    val1 = 9;
            }

            if (val1 < val2) {
                val1 += 10;
                r = 1;
            }
            res.push_back((val1 - val2) + '0');
        }

        for (int i = 0; i < res.size() / 2; i++)
            swap(res[i], res[res.size()-1-i]);
        if (res == "")
            res = "0";
        return res;
    };

    // 1st and 3rd Case
    if (this->sign == other.sign) {
        int remainder = 0;
        res.fracPart = add(this->fracPart, other.fracPart, remainder, 0);
        res.intPart = add(this->intPart, other.intPart, remainder, 1);
        res.realNumber = res.intPart + "." + res.fracPart;
        res.sign = this->sign;
    }

    // 2nd Case
    else if (this->sign != other.sign) {
        int remainder = 0;
        if (this->compMagnitude(other) >= 0) {
            res.fracPart = subtract(this->fracPart, other.fracPart, remainder, 0);
            res.intPart = subtract(this->intPart, other.intPart, remainder, 1);
            res.realNumber = res.intPart + "." + res.fracPart;
            res.sign = this->sign;
        }
        else {
            res.fracPart = subtract(other.fracPart, this->fracPart, remainder, 0);
            res.intPart = subtract(other.intPart, this->intPart, remainder, 1);
            res.realNumber = res.intPart + "." + res.fracPart;
            res.sign = other.sign;
        }
    }

    return res;
}

BigReal BigReal::operator-(BigReal &other) {
    // subtracting simply means flipping the sign of the second number and adding them
    BigReal res;

    other.sign *= -1;
    res = *this + other;
    other.sign *= -1;

    return res;
}

BigReal BigReal::operator-(BigReal &&other) {
    // subtracting simply means fliping the sign of the second number and adding them
    BigReal res;

    other.sign *= -1;
    res = *this + other;
    other.sign *= -1;

    return res;
}

// returning 1 if the first number is larger, -1 if the second number is larger, and 0 if they are equal.
int BigReal::compMagnitude(const BigReal &num) const {
    if (this->intPart.size() > num.intPart.size())
        return 1;
    else if (this->intPart.size() < num.intPart.size())
        return -1;

    for (int i = 0; i < this->intPart.size(); i++) {
        if (this->intPart[i] > num.intPart[i])
            return 1;
        else if (this->intPart[i] < num.intPart[i])
            return -1;
    }

    // making the fraction string equal to compare digit by digit
    string frac1 = this->fracPart, frac2 = num.fracPart;
    int diff = max(frac1.size(), frac2.size()) - min(frac1.size(), frac2.size());
    string tmp(diff, '0');
    if (frac1.size() < frac2.size())
        frac1 += tmp;
    else if (frac1.size() > frac2.size())
        frac2 += tmp;

    for (int i = 0; i < frac1.size(); i++) {
        if (frac1[i] > frac2[i])
            return 1;
        else if (frac1[i] < frac2[i])
            return -1;
    }

    // if the numbers are equal return 0
    return 0;
}

bool BigReal::operator<(const BigReal &other) const {
    if (this->sign < other.sign ||
        this->sign == other.sign && this->sign == 1 && this->compMagnitude(other) < 0 ||
        this->sign == other.sign && this->sign == -1 && this->compMagnitude(other) > 0)
        return 1;
    return 0;
}
bool BigReal::operator>(const BigReal &other) const {
    // if not less than or equal then it is greater than
    if (! (*this < other || *this == other))
        return 1;
    return 0;
}
bool BigReal::operator==(const BigReal &other) const {
    if (this->sign == other.sign && !this->compMagnitude(other))
        return 1;
    return 0;
}

ostream &operator<<(ostream &os, const BigReal &num) {
    if (num.sign < 0)
        os << '-';
    os << num.realNumber;
}












