#ifndef ASSIGNMENT_2_BIGREAL_H
#define ASSIGNMENT_2_BIGREAL_H

#include <string>

using namespace std;

class BigReal {
private:
    string realNumber, intPart, fracPart;
    int sign;
    bool isValidReal(string number);
    void initParts(string number);
public:
    BigReal(double number);
    BigReal(string number);
    BigReal(const BigReal &other);
    BigReal &operator= (const BigReal &other);

    void setNum (string number);
    int size();
    int isPositive();

    BigReal operator+ (BigReal& other);
};


#endif //ASSIGNMENT_2_BIGREAL_H
