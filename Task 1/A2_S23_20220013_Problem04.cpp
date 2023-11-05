// File: A2_S23_20220013_Problem01.cpp
// Purpose: .........
// Author: Ahmed tamer fathy
// Section: S23
// ID: 20220013
// TA: mohamed talaat
// Date: 26 Oct 2023

#include <iostream>

using namespace std;

int *sieve(int n);

int main() {
    int n;
    cin >> n;

    int *primes = sieve(n);

    cout << "The prime numbers up to " << n << " are: ";
    for (int i = 0; i <= n; i++) {
        if (primes[i] == -1)
            break;
        cout << primes[i] << ' ';
    }

    delete[] primes;

    return 0;
}

int *sieve(int n) {
    int *primes = new int[n+1], *visited = new int[n+1];
    int idx = 0;

    for (int i = 0; i <= n; i++) {
        visited[i] = 0;
        primes[i] = -1;
    }

    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            primes[idx++] = i;
            for (long long j = i * i; j <= n; j += i)
                visited[j] = 1;
        }
    }

    delete[] visited;

    return primes;
}
