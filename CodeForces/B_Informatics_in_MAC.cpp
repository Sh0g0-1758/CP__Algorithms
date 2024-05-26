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
        ll n;cin>>n;
        vector<ll> a(n);
        for(auto &i:a) cin>>i;
        vector<ll> cnt(*max_element(a.begin(),a.end())+1,0);
        for(auto it : a) cnt[it]++;
        if(cnt[0] == 0) {
            cout<<2<<endl;
            cout<<1<<" "<<1<<endl;
            cout<<2<<" "<<n<<endl;
        } else if(cnt[0] == 1) {
            cout<<-1<<endl;
        } else {
            bool flag = false;
            ll elem = 0;
            for(ll i = 1;i < cnt.size();i++) {
                if(cnt[i] == 0) {
                    elem = i;
                    break;
                } else if(cnt[i] == 1) {
                    flag = true;
                    break;
                }
            }
            if(elem == 0) elem = cnt.size();
            if(flag) cout << -1 << endl;
            else {
                vector<ll> visit(elem,0);
                ll idx = 0;
                ll counter = 0;
                for(ll i = 0; i < n;i++) {
                    if(a[i] < elem) {
                        if(visit[a[i]] == 0) counter++;
                        visit[a[i]] = 1;
                        if(counter == elem) {
                            idx = i;
                            break;
                        }
                    }
                }
                vector<ll> visit_check(elem,0);
                for(ll i = idx+1;i<n;i++) {
                    if(a[i] < elem) {
                        visit_check[a[i]] = 1;
                    }
                }
                if(accumulate(visit_check.begin(),visit_check.end(),0) != elem) {
                    cout<<-1<<endl;
                } else {
                    cout<<2<<endl;
                    cout<<1<<" "<<idx+1<<endl;
                    cout<<idx+2<<" "<<n<<endl;
                }
            }
        }
    }
    return 0;
}
