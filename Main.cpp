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
#define       INF                       1000000000000000000LL

typedef       long long                 ll;
typedef       unsigned long long        ull;
typedef       long double               lld;

#ifdef        LOCAL
#include      "debug.h"
#else
#define       debug(x)
#endif

#define       int                       long long

void solve()
{
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector<vi> dp(n + 1, vi(m + 1));
    s = "#" + s; t = "#" + t;
    int ans = 0;
    frange(i, 1, n) {
        frange(j, 1, m) {
            int pos = max(dp[i - 1][j], dp[i][j - 1]) - 1;
            if (s[i] == t[j]) pos = max(pos, dp[i - 1][j - 1] + 2);
            dp[i][j] = max(pos, 0ll);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << nline;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr);
#endif
    auto begin = chrono::high_resolution_clock::now(); fastio();
    int t = 1;
    while (t--) solve();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << fixed << "Time measured <= *_* => " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}