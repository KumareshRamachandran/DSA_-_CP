#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define fall(x, n) for(int x=0; x<n; x++)
#define rall(x, n) for(int x=n-1; x>=0; x--)
#define frange(x, start, end) for(int x=start; x<=end; x++)
#define rrange(x, start, end) for(int x=start; x>=end; x--)
#define set_bits __builtin_popcountll
#define vi vector<int>
#define vii vector<vector<int>>
#define initValues(i, v) for(auto &i: v) cin >> i;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


void solve()
{
    int n, d; cin >> n >> d;
    vi v(n); initValues(i, v);
    sort(all(v));
    debug(v);
    int l = 0, r = n-1;
    int cnt = 0; ll sum = 0;
    while(l<=r){
        debug(l) debug(r)
        if(l==r){
            sum += v[r];
            if(sum>d) cnt++;
            break;
        }
        sum += v[r];
        while(l<r && sum<=d) sum += v[r], l++;
        if(sum > d){
            cnt++; sum = 0;
        }
        r--;
    }
    cout << cnt << nline;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    fastio();
    int t = 1;
    // cin >> t;
    // cin.ignore();
    while (t--)
    {
        solve();
    }
    return 0;
}