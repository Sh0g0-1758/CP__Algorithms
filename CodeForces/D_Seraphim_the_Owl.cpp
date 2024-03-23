// All complex things are inherently simple. If you can't explain something simply,
// you just don't understand it well enough.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define endl "\n"

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,m;
        cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        ll src = n;
        ll tgt = m-1;
        ll ans = 0;
        for(ll i = n-1;i>=0;i--) {
            if(src <= tgt) {
                break;
            }
            if(src == tgt+1) {
                if(i == 0) {
                    ans+=a[i];
                    src--;
                } else {
                    vector<ll> str1;
                    str1.push_back(b[i]);
                    ll tmpans = a[i];
                    for(int j = i - 1;j>=0;j--) {
                        tmpans = min(tmpans, str1.back() + a[j]);
                        str1.push_back(b[j] + str1.back());
                    }
                    debug(str1);
                    ans += tmpans;
                    src--;
                }
            } else {
                ans += min(a[i],b[i]);
                src--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}