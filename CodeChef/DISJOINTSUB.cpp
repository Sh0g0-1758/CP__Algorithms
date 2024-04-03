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
#define setbits(x) __builtin_popcountll(x)
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
        vector<ll> a(n);
        for(ll i=0;i<n;i++)
        {
            cin >> a[i];
        }
        vector<ll> indices;
        for(ll i = 1; i < n;i++) {
            if(a[i] < a[i-1]) {
                indices.push_back(i);
            }
        }
        bool flag = true;
        for(ll i = 1; i < indices.size();i++) {
            if(indices[i] - indices[i-1] == 1) {
                cout << "No" << endl;
                flag = false;
                break;
            }
        }
        if (flag) {
            vector<ll> min_arr;
            vector<ll> max_arr;
            bool inner_flag = true;
            // debug(indices)
            for(ll i = 0; i < indices.size();i++) {
                if(indices[i] != n-1) {
                    if(a[indices[i]+1] < a[indices[i]-1]) {
                        cout << "No" << endl;
                        inner_flag = false;
                        break;
                    } else {
                        min_arr.push_back(a[indices[i] - 1] - a[indices[i]]);
                        max_arr.push_back(a[indices[i] + 1] - a[indices[i]]);
                    }
                } else {
                    // debug(min_arr)
                    min_arr.push_back(a[indices[i] - 1] - a[indices[i]]);
                    // debug(min_arr)
                }
            }
            // debug(inner_flag)
            if(inner_flag) {
                ll lower = INT_MIN;
                if(min_arr.size() != 0) lower = *max_element(min_arr.begin(),min_arr.end());
                ll upper = INT_MAX;
                if(max_arr.size() != 0) upper = *min_element(max_arr.begin(),max_arr.end());
                if(lower <= upper) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    }
    return 0;
}