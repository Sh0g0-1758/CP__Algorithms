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
        ll n,m,x;
        cin >> n >> m >> x;
        vector<ll> distances(m);
        vector<ll> directions(m);
        for(ll i=0;i<m;i++)
        {
            cin >> distances[i];
            char temp;
            cin >> temp;
            if(temp == '0') {
                directions[i] = 0;
            } else if (temp == '1') {
                directions[i] = 1;
            } else {
                directions[i] = -1;
            }
        }
        vector<ll> ans;
        ans.push_back(x);
        for(ll j = 0; j < m;j++) {
            ll temp = ans.size();
            for(ll i = 0; i < temp;i++) {
                if(directions[j] == 0) {
                    ll tmp1 = (ans[0] + distances[j]) % n;
                    if(tmp1 == 0) {
                        tmp1 = n;
                    }
                    ans.erase(ans.begin());
                    ans.push_back(tmp1);
                } else if (directions[j] == -1) {
                    ll tmp1 = (ans[0] - distances[j] + n) % n;
                    ll tmp2 = (ans[0] + distances[j]) % n;
                    if(tmp1 == 0) {
                        tmp1 = n;
                    }
                    if(tmp2 == 0) {
                        tmp2 = n;
                    }
                    ans.erase(ans.begin());
                    ans.push_back(tmp1);
                    ans.push_back(tmp2);
                } else {
                    ll tmp1 = (ans[0] - distances[j] + n) % n;
                    if(tmp1 == 0) {
                        tmp1 = n;
                    }
                    ans.erase(ans.begin());
                    ans.push_back(tmp1);
                }
            }
            sort(ans.begin(),ans.end());
            ans.resize(distance(ans.begin(),unique(ans.begin(),ans.end())));
        }
        cout << ans.size() << endl;
        for(auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}