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

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
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
        string s1,s2;
        cin >> n >> s1 >> s2;
        ll result = INT_MAX;
        string ans = s1.substr(0,1) + s2.substr(0,n);
        debug(ans)
        string tmpans = ans;
        for(ll i = 1;i < n;i++) {
            string temp = s1.substr(0,i+1) + s2.substr(i,n-i);
            debug(temp)
            if(temp[i] < ans[i]) {
                bool flag = true;
                for(int j = 0; j < i;j++) {
                    if(temp[j] > ans[j]) {
                        flag = false;
                    }
                }
                if(flag) ans = temp;
            }
        }
        ll cnt = 0;
        for(ll i = 0;i < n;i++) {
            string temp = s1.substr(0,i+1) + s2.substr(i,n-i);
            if(temp == ans) {
                cnt++;
            }
        }
        cout << ans << endl;
        cout << cnt << endl;
    }
    return 0;
}