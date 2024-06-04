// All complex things are inherently simple. If you can't explain something simply,
// you just don't understand it well enough.


// ###########################################
// ##		author: __Legacy__				##
// ##		date: 04-06-2024 13:42:11		##
// ###########################################


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

vector<ll> get_best_three(vector<ll> a) {
    vector<ll> ans;
    ll mx1=-1,mx2=-1,mx3=-1;
    for(ll i=0;i<a.size();i++) {
        if(mx1 == -1 or a[i]>a[mx1]) {
            mx3=mx2;
            mx2=mx1;
            mx1=i;
        } else if(mx2 == -1 or a[i]>a[mx2]) {
            mx3=mx2;
            mx2=i;
        } else if(mx3 == -1 or a[i]>a[mx3]) {
            mx3=i;
        }
    }
    ans.push_back(mx1);
    ans.push_back(mx2);
    ans.push_back(mx3);
    return ans;
}

int main()
{
    fastio();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;cin>>n;
        vector<ll> a(n),b(n),c(n);
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];
        for(ll i=0;i<n;i++) cin>>c[i];
        ll ans = 0;
        for(auto first : get_best_three(a)) {
            for(auto second : get_best_three(b)) {
                for(auto third : get_best_three(c)) {
                    if(first!=second && second!=third && first!=third) ans = max(ans, a[first]+b[second]+c[third]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}