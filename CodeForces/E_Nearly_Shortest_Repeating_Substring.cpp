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
        string s;
        cin >> n;
        cin >> s;
        vector<ll> divisor;
        for(ll i = 1; i <= n;i++) {
            if(n % i == 0) {
                divisor.push_back(i);
            }
        }
        ll ans1 = INT_MAX,ans2 = INT_MAX;
        for(auto it : divisor) {
            string temp_str = s.substr(0,it);
            string add_str = temp_str;
            for(ll i = 1; i < n/it;i++) {
                temp_str+=add_str;
            }
            ll cnt = 0;
            for(ll i = 0; i < n;i++) {
                if(s[i] != temp_str[i]) cnt++;
            }
            if(cnt <= 1) {
                ans1 = it;
                break;
            }
        }
        reverse(s.begin(),s.end());
        for(auto it : divisor) {
            string temp_str = s.substr(0,it);
            string add_str = temp_str;
            for(ll i = 1; i < n/it;i++) {
                temp_str+=add_str;
            }
            ll cnt = 0;
            for(ll i = 0; i < n;i++) {
                if(s[i] != temp_str[i]) cnt++;
            }
            if(cnt <= 1) {
                ans2 = it;
                break;
            }
        }
        cout << min(ans1,ans2) << endl;
    }
    return 0;
}
