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

int main()
{
    fastio();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,m,k,d;
        cin>>n>>m>>k>>d;
        vector<vector<ll>> river(n,vector<ll>(m,0));
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                cin>>river[i][j];
            }
        }
        vector<ll> ans;
        for(ll i = 0;i < n;i++) {
            vector<ll> dp(m,0);
            multiset<ll> mst = {1};
            dp[0] = 1;
            for(ll j = 1; j < m - 1;j++) {
                dp[j] = *mst.begin() + river[i][j] + 1;
                if (j - d - 1 >= 0) mst.erase(mst.find(dp[j - d - 1]));
                mst.insert(dp[j]);
                debug(dp[j])
            }
            ans.push_back(*mst.begin() + 1);
        }
        debug(ans)
        long long cur = 0;
        for (ll i = 0; i < k; i++)
            cur += ans[i];
        long long mn = cur;

        for (int i = k; i < n; i++) {
            cur += ans[i] - ans[i - k];
            mn = min(cur, mn);
        }
        cout << mn << endl;
    }
    return 0;
}