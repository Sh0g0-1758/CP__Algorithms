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
        ll n,m,k;
        cin >> n >> m >> k;
        vector<ll> problems(n);
        vector<ll> models(m);
        vector<ll> functions(k);
        for(ll i=0;i<n;i++)
            cin >> problems[i];
        for(ll i=0;i<m;i++)
            cin >> models[i];
        for(ll i=0;i<k;i++)
            cin >> functions[i];
        sort(models.begin(), models.end());
        sort(functions.begin(), functions.end());
        ll ind;
        ll ans = INT_MIN;
        for(ll i = 1; i < n;i++) {
            if(problems[i] - problems[i-1] > ans) {
                ans = problems[i] - problems[i-1];
                ind = i;
            }
        }
        ll tgt = (problems[ind] + problems[ind-1]) / 2;
        debug(tgt)
        for(ll i = 0; i < m;i++) {
            ll p = upper_bound(functions.begin(), functions.end(), tgt - models[i]) - functions.begin();
            ll sum1 = -1,sum2 = -1;
            if(p != k) sum1 = functions[p] + models[i];
            if(p != 0) sum2 = functions[p-1] + models[i];
            if(sum1 != -1) ans = min(ans, max(abs(sum1 - problems[ind]), abs(sum1 - problems[ind-1])));
            if(sum2 != -1) ans = min(ans, max(abs(sum2 - problems[ind]), abs(sum2 - problems[ind-1])));
        }
        for(ll i = 1; i < n;i++) {
            if(i == ind) continue;
            ans = max(ans, problems[i] - problems[i-1]);
        }
        cout << ans << endl;
    }
    return 0;
}