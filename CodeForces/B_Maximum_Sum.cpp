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

ll power(ll x, ll y, ll p)
{ 
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 

int main()
{
    fastio();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,k;
        cin >> n >> k;
        vector<ll> a(n,0);
        for(ll i=0;i<n;i++)
        {
            cin >> a[i];
        }
        ll max_sum = INT_MIN;
        ll temp_sum = 0;
        ll orignial_sum = 0;
        for(auto it : a)
        {
            orignial_sum = (orignial_sum + it);
            temp_sum = (temp_sum + it);
            if(temp_sum > max_sum)
            {
                max_sum = temp_sum;
            }
            if(temp_sum < 0)
            {
                temp_sum = 0;
            }
        }
        if(max_sum < 0)
        {
            max_sum = 0;
        }
        orignial_sum = (orignial_sum % MOD + MOD) % MOD;
        max_sum = max_sum % MOD;
        ll answer = (orignial_sum + (max_sum * (power(2,k,MOD) - 1)) + MOD) % MOD;
        cout << answer << endl;
    }
    return 0;
}