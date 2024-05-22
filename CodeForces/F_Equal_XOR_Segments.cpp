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
        ll n,q;
        cin>>n>>q;
        vector<ll> a(n,0);
        for(auto &i:a)
            cin>>i;
        while (q--) {
            ll l,r;
            cin>>l>>r;
            l--;r--;
            ll start = a[l];
            for(ll i = l+1;i<=r;i++) {
                start = start^a[i];
            }
            if(start == 0) {
                cout<< "YES" << endl;
                continue;
            }
            ll second_start = a[l];
            if(second_start == start) {
                ll third_start = a[l+1];
                if(third_start == start) {
                    cout << "YES" << endl;
                    continue;
                }
                bool flag = false;
                for(ll i = l+2;i<=r;i++) {
                    third_start = third_start^a[i];
                    if(third_start == start) {
                        flag = true;
                        break;
                    }
                }
                if(flag) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
                continue;
            }
            bool flag = false;
            ll count = 0;
            for(ll i = l+1; i <= r-2;i++) {
                second_start = second_start^a[i];
                if(second_start == start) {
                    count++;
                    second_start = 0;
                    if(count == 2) {
                        flag = true;
                        break;
                    }
                }
            }
            debug(second_start);
            debug(start)
            if (flag) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}