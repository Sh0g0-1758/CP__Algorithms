// All complex things are inherently simple. If you can't explain something simply,
// you just don't understand it well enough.


// ##################################
// ##  author: __Legacy__          ##
// ##  date: 11-06-2024 13:24:00   ##
// ##################################


#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


#define endl "\n"
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define invec(a) for(auto &i:a)cin>>i;
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


template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(stack <T> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "]";}
template <class T> void _print(queue <T> v) {cerr << "[ "; while (!v.empty()) {_print(v.front()); cerr << " "; v.pop();} cerr << "]";}
template <class T> void _print(priority_queue <T> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "]";}
template <class T> void _print(deque <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}


int main()
{
    fastio();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n,x;cin>>n>>x;
        vector<ll> a(n);invec(a)
        sort(a.begin(),a.end());
        vector<ll> result(n);result[0] = 0;
        for(ll i = 1; i < n;i++) {
            result[i] = result[i - 1] + (a[i] - a[i-1]) * i;
        }
        int u = upper_bound(result.begin(),result.end(),x) - result.begin();
        int l = lower_bound(result.begin(),result.end(), x) - result.begin();
        if(u != l) {
            cout<<a[l]<<endl;
        } else {
            l--;
            ll temp = result[l];
            ll ans = a[l] + (x - temp) / (l + 1);
            cout<<ans<<endl;
        }
    }
    return 0;
}