#include <bits/stdc++.h>

using namespace std;

string sum(string a, string b) {
    if (sz(a) >= sz(b)) swap(a, b);
    int carry = 0;
    rall(i, sz(a)) {
        int A = (a[i] - '0') + (b[sz(b) - sz(a) + i] - '0') + carry;
        if (A > 9) {
            A %= 10; carry = 1;
        } else carry = 0;
        b[sz(b) - sz(a) + i] = (A + '0');
    }
    rall(i, sz(b) - sz(a)) {
        int A = (b[i] - '0') + carry;
        if (A > 9) {
            A %= 10; carry = 1;
        } else carry = 0;
        b[i] = (A + '0');
    }
    if (carry) b = '1' + b;
    return b;
}

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

#define int long long

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

signed main() {
    int maxLimit = 2e6;
    vector<int> spf;
    sieve(maxLimit, spf);
    int cnt = 0;
    for (int i = 2; i < maxLimit + 1; ++i)
    {
        if (spf[i] == i) {
            cnt++;
            if (cnt == 1e5) {
                cout << i << '\n';
            }
        }
    }
    cout << cnt;
    return 0;
}
