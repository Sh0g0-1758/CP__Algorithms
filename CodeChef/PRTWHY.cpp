// All complex things are inherently simple. If you can't explain something simply,
// you just don't understand it well enough.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define endl "\n"
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define INF 1e18
#define setbits(x) __builtin_popcountll(x)
using cd = complex<double>;
const double PI=acos(-1);

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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

map<pair<ll,ll> ,ll> mult;

void dfs(ll v, ll p, vector<bool> &visited, vector<ll> &tin, vector<ll> &low, vector<vector<ll>> & adj, ll &timer,ll &ans) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (auto w : adj[v]) {
        if (w == p) continue;
        if (visited[w]) {
            low[v] = min(low[v], tin[w]);
        } else {
            dfs(w, v, visited, tin, low, adj, timer,ans);
            low[v] = min(low[v], low[w]);
            if (low[w] > tin[v]) {
                if(mult[{v,w}]==1){
                    ans++;
                }
            }
        }
    }
}

void find_bridges(ll n, vector<vector<ll>> &adj, ll& ans) {
    vector<pair<ll,ll>> bridges;
    ll timer = 0;
    vector<bool> visited(n,false);
    vector<ll> tin(n,-1), low(n,-1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i, -1, visited, tin, low, adj, timer,ans);
    }
}

int main()
{
    fastio();
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> graph(n);

        for(ll i = 0; i < m;i++) {
            ll a,b;
            cin>>a>>b;
            if (mult.find({a-1,b-1})!=mult.end()) {
                mult[{a-1,b-1}]++;
                mult[{b-1,a-1}]++;
                continue;
            }
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
            mult[{a-1,b-1}]=1;
            mult[{b-1,a-1}]=1;
        }
        ll cnt = 0;
        find_bridges(n, graph,cnt);
        cout << m-cnt << endl;
    }
    return 0;
}