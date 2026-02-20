#include <bits/stdc++.h>

using namespace std;

mt19937_64    rng(chrono::steady_clock::now().time_since_epoch().count());

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
#define       in(i, v)                  for(auto &i: v) cin >> i;
#define       vi                        vector<int>
#define       ii                        pair<int, int>
#define       sz(x)                     ((int)(x).size())
#define       all(x)                    (x).begin(), (x).end()
#define       mod                       1000000007
#define       INF                       0x1fffffffffffffffLL

typedef       long long                 ll;
typedef       unsigned long long        ull;
typedef       long double               lld;

#ifdef        LOCAL
#include      "debug.h"
#else
#define       debug(x)
#endif

// *find_by_order // order_of_key
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordst;

#define       int                       long long

int rngnum(int a, int b) {
    return a + (rng() % (b - a + 1));
}

bool isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

void solve()
{
    int n = rngnum(2, 4);
    cout << n << nline;
    fall(i, n) cout << rngnum(2, 5) << " ";
    cout << nline;
    debug(isPrime(67))
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr);
#endif
    auto begin = chrono::high_resolution_clock::now(); fastio();
    int t = 3;
    while (t--) solve();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << fixed << "Time measured <= *_* => " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}