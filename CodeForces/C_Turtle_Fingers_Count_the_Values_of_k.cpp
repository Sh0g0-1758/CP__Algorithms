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

/* Returns 1 if y is a power of x */
bool isPower(ll x, ll y)
{
    // The only power of 1 is 1 itself
    if (x == 1)
        return (y == 1);
 
    // Repeatedly compute power of x
    ll pow = 1;
    while (pow < y)
        pow *= x;
 
    // Check if power of x becomes y
    return (pow == y);
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    while (t--)
    {
        ll a,b,l;
        cin>>a>>b>>l;
        set<ll> k;
        ll tmp1 = l;
        ll cnt1 = 0, cnt2 = 0;
        if(a>b) swap(a,b);
        while(tmp1%a==0)
        {
            cnt1++;
            tmp1/=a;
        }
        tmp1 = l;
        while(tmp1%b==0)
        {
            cnt2++;
            tmp1/=b;
        }
        ll y = 1;
        for(ll i = 0; i < cnt1+1;i++) {
            tmp1 = l;
            tmp1 = tmp1 / y;
            ll z = 1;
            for(ll j = 0; j < cnt2+1;j++) {
                if(tmp1 % z == 0) {
                    k.insert(tmp1/z);
                }
                z=z*b;
            }
            y=y*a;
        }
        cout << k.size() << endl;
    }
    return 0;
}