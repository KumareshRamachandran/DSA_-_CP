#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

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

typedef       long long                 ll;
typedef       unsigned long long        ull;
typedef       long double               lld;

#ifdef        LOCAL
#include      "debug.h"
#else
#define       debug(x)
#endif

#define       int                       long long

//----------Ordered Set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordst;
//---------------------

//------------DSU
struct DSU {
    vi e; void init(int N) { e = vi(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};
//---------------

//---------------Segment Tree
typedef int item;

struct SegmentTree {
    int size;
    vector<item> values;

    item NEUTRAL_VALUE = 0;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        values.assign(2 * size, item());
    }

    item single(int v) {
        return v;
    }

    item merge(item &s1, item &s2) {
        return s1 + s2;
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
//-------------------

//-------------------Short Segment Tree
struct Tree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return __gcd(a, b); }
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};
//--------------------

//-------------------Bridge Counter
void bridge(int node, int parent) {
    vis[node] = 1;
    low[node] = ord[node] = timer++;
    for (auto &i : adj[node]) {
        if (i == parent) continue;
        if (vis[i]) {
            low[node] = min(low[node], ord[i]);
        } else {
            bridge(i, node);
            low[node] = min(low[node], low[i]);
            if (low[i] > ord[node]) {
                brdg.pb({node, i});
            }
        }
    }
}

//-------------------

//-------------------DFS node count
int dfs(int node) {
    int cur = 1;
    vis[node] = 1;
    for (auto &i : adj[node]) {
        if (!vis[i]) {
            cur += dfs(i);
        }
    }
    return cnt[node] = cur;
}
//-------------------

//-------------------Sparse Table (Errichto)
const int MAX_N = 100005;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG];
int bin_log[MAX_N];

int query(int L, int R) {
    int length = R - L + 1;
    int k = bin_log[length];
    return min(m[L][k], m[R - (1 << k) + 1][k]);
}

void build(int n) {
    bin_log[1] = 0;
    for (int i = 2; i <= n; i++) {
        bin_log[i] = bin_log[i / 2] + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[i][0] = a[i];
    }
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i + (1 << k) - 1 < n; i++) {
            m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }
}
//------------------------

//------------------------Binary Lifting
int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}
//------------------------

void solve()
{

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