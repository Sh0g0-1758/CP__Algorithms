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

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

ll kruskals_mst(ll V, vector<vector<ll>> edgelist, bool flag, vector<bool> &visited_edges, DSU &s)
{
    sort(edgelist.begin(), edgelist.end());
    if (!flag)
        reverse(edgelist.begin(), edgelist.end());
    int ans = 0;
    for (auto edge : edgelist)
    {
        int w = edge[0];
        int x = edge[1];
        int y = edge[2];
        if (s.find(x) != s.find(y))
        {
            s.unite(x, y);
            visited_edges[x] = true;
            visited_edges[y] = true;
            ans += w;
        }
    }
    return ans;
}

int main()
{
    fastio();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll N, M1, M2;
        cin >> N >> M1 >> M2;
        vector<ll> graph[N];
        vector<vector<ll>> edgelist;
        vector<vector<ll>> edgelist2;
        for (ll i = 0; i < M1; i++)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(v);
            graph[v].push_back(u);
            if (u > v)
                swap(u, v);
            edgelist.push_back({w, u, v});
        }
        for (ll i = 0; i < M2; i++)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(v);
            graph[v].push_back(u);
            if (u > v)
                swap(u, v);
            edgelist2.push_back({w, u, v});
        }
        vector<bool> visited_edges(N, false);
        DSU s(N);
        ll max_cost = kruskals_mst(N, edgelist2, false, visited_edges, s);
        ll min_cost = kruskals_mst(N, edgelist, true, visited_edges, s);
        bool flag = true;
        for (auto it : visited_edges)
        {
            if (!it)
            {
                cout << "Impossible" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << max_cost << " " << min_cost + max_cost << endl;
    }
    return 0;
}