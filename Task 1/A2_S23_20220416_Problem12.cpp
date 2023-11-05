// File: A2_S23_20220416_Problem12.cpp
// Purpose: .........
// Author: Youssef Nasser Mohamed
// Section: S23
// ID: 20220416
// TA: mohamed talaat
// Date: 30 Oct 2023

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <cctype>

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
    vector<string> words = {"urgent", "verify", "password", "account", "payment", "suspicious", "update", "unusual", "confirm", "information", "security", "login", "bank", "notification", "action", "due", "attention", "review", "access", "email", "free", "win", "prize", "risk", "emergency", "warning", "failure", "immediate", "limited", "data"};
    ifstream inputFile("email.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening the file." << endl;
        return 1;
    }
    string line;
    unordered_map<string, int> values = {};
    unordered_map<string, int> m = {};
    values["urgent"] = 1;
    values["verify"] = 2;
    values["password"] = 3;
    values["account"] = 2;
    values["payment"] = 3;
    values["suspicious"] = 2;
    values["update"] = 1;
    values["unusual"] = 1;
    values["confirm"] = 1;
    values["information"] = 1;
    values["security"] = 3;
    values["login"] = 2;
    values["bank"] = 2;
    values["notification"] = 1;
    values["action"] = 1;
    values["due"] = 1;
    values["attention"] = 1;
    values["review"] = 2;
    values["access"] = 2;
    values["email"] = 2;
    values["win"] = 3;
    values["free"] = 5;
    values["prize"] = 4;
    values["risk"] = 1;
    values["emergency"] = 3;
    values["warning"] = 2;
    values["failure"] = 1;
    values["immediate"] = 2;
    values["limited"] = 2;
    values["data"] = 2;
    for (int i = 0; i < words.size(); ++i)
    {
        m[words[i]] = 0;
    }
    int totalPoints = 0;

    while (getline(inputFile, line))
    {
        transform(line.begin(), line.end(), line.begin(), [](unsigned char c)
                  { return tolower(c); });
        vector<string> vec = split(line, " ");
        for (int i = 0; i < vec.size(); ++i)
        {
            for (int j = 0; j < words.size(); ++j)
            {
                if (vec[i].find(words[j], 0) != string::npos)
                {
                    m[words[j]] += 1;
                    totalPoints += values[words[j]];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < words.size(); ++i)
    {
        cout << words[i] << " => " << m[words[i]] << "  "
             << "Point-Total => " << m[words[i]] * values[words[i]] << "\n";
    }
    cout << "\nFinal-Point-Total => " << totalPoints << "\n";
    return 0;
}
