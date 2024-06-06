// All complex things are inherently simple. If you can't explain something simply,
// you just don't understand it well enough.


// ##################################
// ##  author: __Legacy__          ##
// ##  date: 06-06-2024 17:19:27   ##
// ##################################


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


template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(stack <T> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "]";}
template <class T> void _print(queue <T> v) {cerr << "[ "; while (!v.empty()) {_print(v.front()); cerr << " "; v.pop();} cerr << "]";}
template <class T> void _print(priority_queue <T> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "]";}
template <class T> void _print(deque <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

void dfs(ll i,ll j,vector<vector<char>> &graph,vector<vector<bool>> &vis,ll n,ll m) {
    if(i < 0 or j < 0 or i >= n or j >= m or graph[i][j] == '#' or vis[i][j] == true)
        return;
    vis[i][j] = true;
    dfs(i+1,j,graph,vis,n,m);
    dfs(i-1,j,graph,vis,n,m);
    dfs(i,j+1,graph,vis,n,m);
    dfs(i,j-1,graph,vis,n,m);
}

int main()
{
    fastio();
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n,m;cin>>n>>m;
        ll ans = 0;
        vector<vector<char>> graph(n,vector<char>(m));
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(ll i=0;i<n;i++) for(ll j=0;j<m;j++) cin>>graph[i][j];
        for(ll i=0;i<n;i++) {
            for(ll j=0;j<m;j++) {
                if(graph[i][j] == '.' and vis[i][j] == false) {
                    dfs(i,j,graph,vis,n,m);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
