// All complex things are inherently simple. If you can't explain something simply,
// you just don't understand it well enough.


// ##################################
// ##  author: __Legacy__          ##
// ##  date: 05-06-2024 15:23:36   ##
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


int main()
{
    fastio();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        string s;cin>>s;
        reverse(s.begin(),s.end());
        ll cnt_low=0,cnt_up=0;
        string ans = "";
        for(auto it : s) {
            if(it == 'b') {
                cnt_low++;
                continue;
            }
            if(it == 'B') {
                cnt_up++;
                continue;
            }
            if(cnt_low > 0) {
                if(it >= 'a' and it <= 'z') {
                    cnt_low--;
                    continue;
                }
            }
            if(cnt_up > 0) {
                if(it >= 'A' and it <= 'Z') {
                    cnt_up--;
                    continue;
                }
            }
            ans += it;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}