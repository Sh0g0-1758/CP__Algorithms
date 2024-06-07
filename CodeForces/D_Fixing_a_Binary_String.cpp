// All complex things are inherently simple. If you can't explain something simply,
// you just don't understand it well enough.


// ##################################
// ##  author: __Legacy__          ##
// ##  date: 07-06-2024 15:11:37   ##
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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll count = 1;
        while (i < n - 1 && s[i] == s[i + 1])
        {
            count++;
            i++;
        }
        v.push_back(count);
    }
    ll i = 0;
    ll siz = v.size();
    while (i < siz && v[i] == k)
        i++;
    if (i == siz)
    {
        cout << n << endl;
    }
    else
    {
        if (v[i] > k)
        {
            if(i == siz-1) cout<<-1<<endl;
            else if (v[i] == 2 * k)
            {
                ll j = i + 1;
                while (j < siz && v[j] == k)
                    j++;
                if (j == siz)
                {
                    if ((siz - i - 1) % 2)
                    {
                        cout << k * (i + 1) << endl;
                    }
                    else
                    {
                        cout << -1 << endl;
                    }
                }
                else
                {
                    cout << -1 << endl;
                }
            }
            else if(v[i] + v[siz-1] == 2*k)
            {
                if((i%2) == (siz-1)%2){
                    ll j = i + 1;
                    while (j < siz - 1 && v[j] == k)
                        j++;
                    if (j == siz - 1)
                    {
                        cout << (k * i) + v[i] - k << endl;
                    }
                    else
                    {
                        cout << -1 << endl;
                    }
                }
                else{
                    cout<<-1<<endl;
                }
            }
 
            else{
                cout<<-1<<endl;
            }
        }
        else
        {
            if (i == siz - 1)
                cout << -1 << endl;
            else
            {
                if (v[i] + v[siz - 1] == k && ((i % 2) == ((siz - 1) % 2)))
                {
                    ll j = i + 1;
                    while (j < siz - 1 && v[j] == k)
                        j++;
                    if (j == siz - 1)
                    {
                        cout << (k * i) + v[i] << endl;
                    }
                    else
                    {
                        cout << -1 << endl;
                    }
                }
                else
                {
                    cout << -1 << endl;
                }
            }
        }
    }

    }
    return 0;
}