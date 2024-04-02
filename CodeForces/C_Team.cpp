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
        cin >> a >> b;
        if (a > b + 1 or b > (2 * (a + 1))) {
            cout << -1 << endl;
        } else if (a == b) {
            for(ll i = 0; i < a;i++) {
                cout << "01";
            }
            cout << endl;
        } else if (a == (b + 1)){
            for(ll i = 0; i < b;i++) {
                cout << "01";
            }
            cout << "0";
            cout << endl;
        } else if (b == (a + 1)) {
            for(ll i = 0; i < a;i++) {
                cout << "10";
            }
            cout << "1";
            cout << endl;
        } else if (b == 2 * a) {
            for(ll i = 0;i < a;i++) {
                cout << "110";
            }
            cout << endl;
        } else if (b - 1 == 2 * a or b - 2 == 2 * a) {
            for(ll i = 0; i < a;i++) {
                cout << "110";
            }
            for(ll i = 0; i < b - 2 * a;i++) {
                cout << "1";
            }
            cout << endl;
        } else if (b > a) {
            while(b > a) {
                a-=1;
                b-=2;
                cout << "110";
            }
            for(ll i = 0; i < a;i++) {
                cout << "10";
            }
            cout << endl;
        }

    // } 
    return 0;
}