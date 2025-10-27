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

int rngnum(int a, int b) {
    return a + (rng() % (b - a + 1));
}

typedef int item;

struct SegmentTree {
    int size;
    vector<item> values;
    item NEUTRAL_VALUE = -INF;
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        values.assign(2 * size, item());
    }
    item single(int v) {
        return v;
    }
    item merge(item &s1, item &s2) {
        return max(s1, s2);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            values[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
    item query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return NEUTRAL_VALUE;
        if (lx >= l && rx <= r) return values[x];
        int m = (lx + rx) / 2;
        item s1 = query(l, r, 2 * x + 1, lx, m);
        item s2 = query(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }
    item query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int solvelogic(int n, vi &v)
{
    vi pos, pre(n);
    SegmentTree sgt; sgt.init(n);
    fall(i, n) sgt.set(i, v[i]);
    fall(i, n) if (v[i] > 0) pos.pb(i);
    partial_sum(all(v), pre.begin());
    int k = sz(pos);
    fall(i, k - 1) {
        frange(j, i + 1, k - 1) {
            int l = pos[i], r = pos[j];
            int sum = pre[r] - (l > 0 ? pre[l - 1] : 0);
            int mx = sgt.query(l, r + 1);
            if (mx < sum) return 0;
        }
    }
    return 1;
}

int solvebrute(int n, vi &v)
{
    fall(i, n) {
        int sum = 0, maxi = -INF;
        frange(j, i, n - 1) {
            sum += v[j];
            maxi = max(maxi, v[j]);
            if (maxi < sum) {
                // debug(mp(i, j))
                // debug(mp(maxi, sum))
                return 0;
            }
        }
    }
    return 1;
}

bool generate() {
    int n = 2e5;
    vi v(n);
    fall(i, n) v[i] = rngnum(-1e9, 1e9);
    if (solvebrute(n, v) != solvelogic(n, v)) {
        cout << n << nline;
        fall(i, n) cout << v[i] << " \n"[i == n - 1];
        return 1;
    }
    return 0;
}

void solve()
{
    fall(i, 1) {
        if (generate())
            break;
    }
    return;
    int n; cin >> n;
    vi v(n); in(i, v);
    cout << solvebrute(n, v) << nline;
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