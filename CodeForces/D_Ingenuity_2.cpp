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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> north;
        vector<ll> south;
        vector<ll> east;
        vector<ll> west;
        for(ll i = 0; i < n;i++) {
            if(s[i] == 'N') north.push_back(i);
            else if(s[i] == 'S') south.push_back(i);
            else if(s[i] == 'E') east.push_back(i);
            else west.push_back(i);
        }
        string ans = "";
        for(ll i = 0; i < n;i++) {
            ans+="X";
        }
        bool turn = true;
        while(north.size() > 0 && south.size() > 0) {
            if(turn) {
                ans[north.back()] = 'R';
                ans[south.back()] = 'R';
                north.pop_back();
                south.pop_back();
                turn = false;
            } else {
                ans[north.back()] = 'H';
                ans[south.back()] = 'H';
                north.pop_back();
                south.pop_back();
                turn = true;
            }
        }
        while(east.size() > 0 && west.size() > 0) {
            if(turn) {
                ans[east.back()] = 'R';
                ans[west.back()] = 'R';
                east.pop_back();
                west.pop_back();
                turn = false;
            } else {
                ans[east.back()] = 'H';
                ans[west.back()] = 'H';
                east.pop_back();
                west.pop_back();
                turn = true;
            }
        }
        if(north.size()%2 == 1 || south.size()%2 == 1 || east.size()%2 == 1 || west.size()%2 == 1) {
            cout << "NO" << endl;
        } else {
            while(north.size() > 0) {
                if(turn) {
                    ans[north.back()] = 'R';
                    north.pop_back();
                    turn = false;
                } else {
                    ans[north.back()] = 'H';
                    north.pop_back();
                    turn = true;
                }
            }
            while(south.size() > 0) {
                if(turn) {
                    ans[south.back()] = 'R';
                    south.pop_back();
                    turn = false;
                } else {
                    ans[south.back()] = 'H';
                    south.pop_back();
                    turn = true;
                }
            }
            while(east.size() > 0) {
                if(turn) {
                    ans[east.back()] = 'R';
                    east.pop_back();
                    turn = false;
                } else {
                    ans[east.back()] = 'H';
                    east.pop_back();
                    turn = true;
                }
            }
            while(west.size() > 0) {
                if(turn) {
                    ans[west.back()] = 'R';
                    west.pop_back();
                    turn = false;
                } else {
                    ans[west.back()] = 'H';
                    west.pop_back();
                    turn = true;
                }
            }
            bool flag_h = false;
            bool flag_r = false;
            for (auto i:ans) {
                if(i != 'R') {
                    flag_h = true;
                }
                if(i != 'H') {
                    flag_r = true;
                }
            }
            if(flag_h && flag_r) cout << ans << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}