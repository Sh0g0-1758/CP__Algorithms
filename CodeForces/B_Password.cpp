// All complex things are inherently simple. If you can't explain something simply,
// you just don't understand it well enough.


// ##################################
// ##  author: __Legacy__          ##
// ##  date: 07-06-2024 21:07:36   ##
// ##################################


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

void process(string s, ll n, ll dp[], ll pa[]) {
    ll p = 31;
    ll pow = p;
    dp[0] = s[0] - 'a' + 1;
    pa[0] = 1;
    for(ll i = 1; i <n;i++) {
        dp[i] = (dp[i-1] + (s[i] - 'a' + 1) * pow ) % MOD;
        pa[i] = pow;
        pow = (pow * p) % MOD;
    }
}

ll hashquery(ll dp[], ll l, ll r) {
    if(l == 0) return dp[r];
    return (dp[r] - dp[l-1] + MOD) % MOD;
}

int main()
{
    fastio();
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        string s;cin>>s;ll n = s.size();
        ll dp[n], pa[n];
        process(s, n, dp, pa);
        ll ans = 0;
        for(ll i = 0; i < n;i++) {
            ll prefix = dp[i];
            ll suffix = hashquery(dp, n-i-1, n-1);
            if((prefix * pa[n-i-1])%MOD == suffix) {
                for(int j = 1,k = i + 1; k < n - 1; j++,k++) {
                    ll mid = hashquery(dp, j, k);
                    if((prefix*pa[j])%MOD == mid) {
                        ans = i + 1;break;
                    }
                }
            }
        }
        if(ans == 0) cout << "Just a legend" << endl;
        else cout << s.substr(0, ans) << endl;
    }
    return 0;
}