// File: A2_S23_20220416_Problem03.cpp
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

vector<string> split(const string &input, const string &delimiter)
{
    vector<string> result;
    long long int start = 0, end = 0;

    while ((end = input.find(delimiter, start)) != string::npos)
    {
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.length();
    }

    result.push_back(input.substr(start));
    return result;
}

int main()
{
    vector<string> vec = split("do, re, mi, fa, so, la, ti, do", ", ");
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << endl;
    }

    return 0;
}
