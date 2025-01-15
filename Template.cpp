#include <bits/stdc++.h>

using namespace std;

mt19937_64    RNG(chrono::steady_clock::now().time_since_epoch().count());

#define       fastio()                  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
#define       vi                        vector<int>
#define       ii                        pair<int, int>
#define       initValues(i, v)          for(auto &i: v) cin >> i;
#define       sz(x)                     ((int)(x).size())
#define       all(x)                    (x).begin(), (x).end()

typedef       long long                 ll;
typedef       unsigned long long        ull;
typedef       long double               lld;

#ifndef       ONLINE_JUDGE
#include      "debug.h"
#else
#define       debug(x)
#endif

#define       int                       long long

void solve()
{
    int n = rand() % 5 + 1, m = rand() % 5 + 1;
    cout << n << " " << m << "new\n";
    fall(i, n) {
        fall(j, m)
        cout << (rand() % 10) << " \n"[j == m - 1];
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr);
#endif
    auto begin = chrono::high_resolution_clock::now(); fastio();
    int t = 1;
    cin >> t; cin.ignore();
    while (t--) solve();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}