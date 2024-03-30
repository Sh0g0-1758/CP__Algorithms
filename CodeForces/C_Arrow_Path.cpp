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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> a(2, vector<ll>(n));
        string s1,s2;
        cin >> s1 >> s2;
        for(ll i = 0; i < n;i++) {
            if(s1[i] == '>') {
                a[0][i] = 1;
            } else {
                a[0][i] = 0;
            }
        }
        for(ll i = 0; i < n;i++) {
            if(s2[i] == '>') {
                a[1][i] = 1;
            } else {
                a[1][i] = 0;
            }
        }
        ll row = 0;
        bool ans = true;
        for(ll i = 0; i < n;) {
            if(a[row][i + 1] == 0) {
                if(a[1-row][i] == 0) {
                    ans = false;
                    break;
                } else {
                    row = 1-row;
                    i+=1;
                }
            } else {
                i+=2;
            }
            if(i == n-1 and row == 1) {
                break;
            }
        }
        if(ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}