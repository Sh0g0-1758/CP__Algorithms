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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int main()
{
    fastio();
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    ll a,b;
    cin>>a>>b;
    vector<ll> ans;
    while(b>9) {
        ans.push_back(9);
        b-=9;
    }
    ans.push_back(b);
    for(ll i = ans.size(); i < a;i++) {
        ans.push_back(0);
    }
    if((ans[0] == 0 and a != 1) or ans.size() > a) {
        cout << -1 << " " << -1;
    } else {
        vector<ll> temp = ans;
        reverse(ans.begin(), ans.end());
        if (ans[0] == 0) {
            for (ll i = 0; i < ans.size(); i++) {
                if(ans[i] != 0) {
                    ans[i]--;
                    ans[0]++;
                    break;
                }
            }
        }
        for(auto it : ans) {
            cout << it;
        }
        cout << " ";
        for(auto it : temp) {
            cout << it;
        }
    }
    // }
    return 0;
}