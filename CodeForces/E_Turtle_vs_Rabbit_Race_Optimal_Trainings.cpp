// All complex things are inherently simple. If you can't explain something simply,
// you just don't understand it well enough.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define endl "\n"
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define INF 1e18
#define setbits(x) __builtin_popcountll(x)
using cd = complex<double>;
const double PI = acos(-1);

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(stack<T> v)
{
    cerr << "[ ";
    while (!v.empty())
    {
        _print(v.top());
        cerr << " ";
        v.pop();
    }
    cerr << "]";
}
template <class T>
void _print(queue<T> v)
{
    cerr << "[ ";
    while (!v.empty())
    {
        _print(v.front());
        cerr << " ";
        v.pop();
    }
    cerr << "]";
}
template <class T>
void _print(priority_queue<T> v)
{
    cerr << "[ ";
    while (!v.empty())
    {
        _print(v.top());
        cerr << " ";
        v.pop();
    }
    cerr << "]";
}
template <class T>
void _print(deque<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

int main()
{
    fastio();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        ll q;
        cin >> q;
        while (q--)
        {
            ll l, u;
            cin >> l >> u;
            u++;
            bool flag = false;
            for (ll i = l - 1; i < n; i++)
            {
                if (u - a[i] < 1)
                {
                    if (((u - 1) * u) / 2 > (((a[i] - u) * (a[i] - u + 1)) / 2))
                        i++;
                    if (i == l - 1)
                        i++;
                    cout << i << " ";
                    flag = true;
                    break;
                }
                else
                {
                    u -= a[i];
                }
            }
            if (!flag)
                cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}