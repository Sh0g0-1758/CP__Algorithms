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
        string s;
        cin >> s;
        bool flag = true;
        for(ll i = 0;i < s.size();i++) {
            if(s[i] == '0' or s[i] == '1') continue;
            else flag = false;
        }
        if(flag) cout << "YES" << endl;
        else {
            ll a = stoi(s);
                        while(a%1010 == 0) {
                a = a / 1010;
            }
                        while(a&1100 == 0) {
                a = a / 1100;
            }
                        while(a%1001 == 0) {
                a = a / 1001;
            }
                        while(a%1011 == 0) {
                a = a / 1011;
            }
                        while(a%1101 == 0) {
                a = a / 1101;
            }
                        while(a%1110 == 0) {
                a = a / 1110;
            }
                        while(a%1111 == 0) {
                a = a / 1111;
            }
                        while(a % 110 == 0) {
                a = a / 110;
            }
                        while(a%101 == 0) {
                a = a / 101;
            }
                        while(a%111 == 0) {
                a = a / 111;
            }
                        while(a%10 == 0) {
                a = a / 10;
            }
            while(a%11 == 0) {
                a = a / 11;
            }
            if(a == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}