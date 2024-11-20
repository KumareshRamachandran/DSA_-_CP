#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void primeFactorization(int n) {
    vector<int> factors;

    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 2) {
        factors.push_back(n);
    }

    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;
}

long long binaryExponentiation(long long a, long long b, long long mod) {
    long long result = 1;
    a = a % mod;

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }

    return result;
}

void sieve(int n, vector<int>& spf) {
    spf.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        spf[i] = i;
    }

    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> getPrimeFactors(int x, const vector<int>& spf) {
    vector<int> factors;
    while (x != 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

int main() {
    int maxLimit = 105;
    vector<int> spf;
    sieve(maxLimit, spf);

    int n = 96;
    // cout << "Enter a number: ";
    // cin >> n;

    // if (n > maxLimit) {
    //     cout << "Number exceeds precomputed limit." << endl;
    //     return 1;
    // }

    // vector<int> factors = getPrimeFactors(n, spf);
    // cout << "Prime factors of " << n << ": ";
    // for (int factor : factors) {
    //     cout << factor << " ";
    // }
    // cout << endl;
    primeFactorization(96);

    return 0;

    return 0;
}
