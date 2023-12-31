// File: A2_S23_20220416_Problem09.cpp
// Purpose: .........
// Author: Youssef Nasser Mohamed
// Section: S23
// ID: 20220416
// TA: mohamed talaat
// Date: 26 Oct 2023

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool bears(int n)
{
    if (n == 42)
    {
        return true;
    }
    bool one = false;
    bool two = false;
    bool three = false;
    if (n < 42)
    {
        return false;
    }
    if (n % 2 == 0)
    {
        one = bears(n / 2);
    }
    if (one)
        return true;
    if (n % 3 == 0 || n % 4 == 0)
    {
        int lastTwoDigits = ((n % 100) / 10) * (n % 10);
        two = bears(n - lastTwoDigits);
    }
    if (two)
        return true;
    if (n % 5 == 0)
    {
        three = bears(n - 42);
    }
    if (three)
        return true;

    return false;
}

int main()
{
    bool test = bears(250);
    if (test)
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}
