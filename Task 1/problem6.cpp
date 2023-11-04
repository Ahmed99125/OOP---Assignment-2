#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void binaryPrint(int n) {
    if (n == 0) {
        cout << 0;
    } else if (n == 1) {
        cout << 1;
    } else {
        binaryPrint(n / 2);
        cout << n % 2;
    }
}

void backTrack(string& prefix, int &k, string res) {
    if(res.length() == k) {
        cout << prefix << res << "\n";
        return;
    }
    backTrack(prefix, k, res + "0");
    backTrack(prefix, k, res + "1");
}

void numbers(string prefix, int k) {
    if(k > 0) {
        backTrack(prefix, k, "");
    }
}

int main()
{
    numbers("00101", 2);
    return 0;
}