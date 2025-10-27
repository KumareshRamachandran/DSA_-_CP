#include <bits/stdc++.h>

using namespace std;

mt19937_64    rng(chrono::steady_clock::now().time_since_epoch().count());

#define       fastio()                  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define       nline                     "\n"
#define       pb                        push_back
#define       ppb                       pop_back
#define       mp                        make_pair
#define       ff                        first
#define       ss                        second
#define       fall(x, n)                for(int x=0; x<n; x++)
#define       rall(x, n)                for(int x=n-1; x>=0; x--)
#define       frange(x, start, end)     for(int x=start; x<=end; x++)
#define       rrange(x, start, end)     for(int x=start; x>=end; x--)
#define       in(i, v)                  for(auto &i: v) cin >> i;
#define       vi                        vector<int>
#define       ii                        pair<int, int>
#define       sz(x)                     ((int)(x).size())
#define       all(x)                    (x).begin(), (x).end()

typedef       long long                 ll;
typedef       unsigned long long        ull;
typedef       long double               lld;

#ifdef        LOCAL
#include      "debug.h"
#else
#define       debug(x)
#endif

#define       int                       long long

//---------------------------------------------------------------------\\
//----------------------- BIG INTEGER SUM -----------------------------\\

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

//---------------------------------------------------------------------\\
//----------------------------- PRIME ---------------------------------\\

bool isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

//---------------------------------------------------------------------\\
//----------------------- PRIME FACTORIZATION -------------------------\\

vi pf(int n) {
    vi fts;
    while (n % 2 == 0) {
        fts.pb(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            fts.pb(i);
            n /= i;
        }
    }
    if (n > 2) fts.pb(n);
    return fts;
}

//---------------------------------------------------------------------\\
//----------------------- BINARY EXPONENTIATION -----------------------\\

int bexp(int a, int b, int M = 1e18) {
    int ans = 1;
    a = a % M;
    while (b > 0) {
        if (b % 2 == 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b /= 2;
    }
    return ans;
}

//---------------------------------------------------------------------\\
//------------------------------ SEIVE --------------------------------\\

void sieve(int n, vi &spf) {
    spf.resize(n + 1);
    frange(i, 1, n) spf[i] = i;
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

//---------------------------------------------------------------------\\
//----------------------- PRIME FACTORIZATION -------------------------\\

vi gpf(int x, vi &spf) {
    vi fts;
    while (x != 1) {
        fts.pb(spf[x]);
        x /= spf[x];
    }
    return fts;
}

//---------------------------------------------------------------------\\
//----------------------- MODULAR ARITHEMETIC -------------------------\\

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
template<typename T> T power(T a, u64 b, T r = 1) { while (b) { if (b & 1) r *= a; a *= a; b >>= 1; } return r; }
i64 safeMod(i64 x, i64 m) { x %= m; if (x < 0) x += m; return x; }
pair<i64, i64> invGcd(i64 a, i64 b) {
    a = safeMod(a, b);
    if (a == 0) return { b, 0 };
    i64 s = b, t = a, m0 = 0, m1 = 1;
    while (t) {
        i64 u = s / t; s -= t * u; m0 -= m1 * u;
        swap(s, t); swap(m0, m1);
    }
    if (m0 < 0) m0 += b / s;
    return { s, m0 };
}
int MOD;
template<typename U>
struct ModIntBase {
    U x;
    ModIntBase() : x(0) {}
    template<typename T> ModIntBase(T v) {
        i64 t = (i64)v % MOD;
        if (t < 0) t += MOD;
        x = (U)t;
    }
    static U mod() { return (U)MOD; }
    U val() const { return x; }
    ModIntBase operator-() const { return x ? ModIntBase(mod() - x) : ModIntBase(0); }
    ModIntBase inv() const { return power(*this, (u64)mod() - 2); }
    ModIntBase& operator*=(const ModIntBase& r) { x = (U)((u64)x * r.x % MOD); return *this; }
    ModIntBase& operator+=(const ModIntBase& r) { x += r.x; if (x >= mod()) x -= mod(); return *this; }
    ModIntBase& operator-=(const ModIntBase& r) { x += mod() - r.x; if (x >= mod()) x -= mod(); return *this; }
    ModIntBase& operator/=(const ModIntBase& r) { return *this *= r.inv(); }
    friend ModIntBase operator*(ModIntBase a, const ModIntBase& b) { return a *= b; }
    friend ModIntBase operator+(ModIntBase a, const ModIntBase& b) { return a += b; }
    friend ModIntBase operator-(ModIntBase a, const ModIntBase& b) { return a -= b; }
    friend ModIntBase operator/(ModIntBase a, const ModIntBase& b) { return a /= b; }
    friend istream& operator>>(istream& is, ModIntBase& a) { i64 v; is >> v; a = ModIntBase(v); return is; }
    friend ostream& operator<<(ostream& os, const ModIntBase& a) { return os << a.val(); }
    friend bool operator==(const ModIntBase& a, const ModIntBase& b) { return a.val() == b.val(); }
    friend bool operator<(const ModIntBase& a, const ModIntBase& b) { return a.val() < b.val(); }
};
using Z = ModIntBase<u32>;

//---------------------------------------------------------------------\\
//-------------------------------- NCR --------------------------------\\

int ncr(int n, int k) {
    if (k > n - k) k = n - k;
    int ans = 1;
    frange(i, 1, k) {
        ans = ans * 1ll * (n - k + i) / i;
    }
    return ans;
}

//---------------------------------------------------------------------\\
//------------------------------Factorial------------------------------\\

vi fact, invFact;

void prefact(int n) {
    fact.assign(n + 1, 0);
    invFact.assign(n + 1, 0);
    fact[0] = 1;
    frange(i, 1, n) fact[i] = (1ll * fact[i - 1] * i) % mod;
    invFact[n] = bexp(fact[n], mod - 2, mod);
    rrange(i, n - 1, 0) invFact[i] = (1ll * (i + 1) * invFact[i + 1]) % mod;
}

void solve()
{
    int n; cin >> n;
    priority_queue<int> pq;
    queue<int> q;
    deque<int> dq;
    set<int> st;
    vi v;
    function<int(int)> f = [&](int n) {
        cout << n << nline;
        v.assign(n, 0); v.resize(n);
        st.insert(n); pq.push(n); pq.top();
        pq.pop();
        int sum = accumulate(all(v), 0ll);
        return 0;
    };
    vi suf(n);
    partial_sum(all(v), suf.rbegin());
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr);
#endif
    auto begin = chrono::high_resolution_clock::now(); fastio();
    int t = 1;
    cin >> t; cin.ignore();
    while (t--) solve();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << fixed << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
