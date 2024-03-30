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
        vector<ll> store;
        for(ll i = 0;i < n;i++) {
            ll x;
            cin >> x;
            store.push_back(x);
        }
        ll elem = 0;
        vector<ll> ans;
        for(int i = 0; i < n;i++) {
            if(store[i] == 1) {
                ans.push_back(elem);
                elem++;
            } else if(store[i] < 1) {
                ans.push_back(elem - store[i]);
            } else {
                ans.push_back(elem);
                vector<ll> temp = ans;
                sort(temp.begin(),temp.end());
                for(ll j = 0; j < temp.size();j++) {
                    if(j != temp[j]) {
                        elem = j;
                        break;
                    }
                    if(j == temp.size()-1) {
                        elem = j + 1;
                    }
                }
            }
        }
        for(auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}