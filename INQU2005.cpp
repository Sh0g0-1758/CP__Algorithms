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

void dfs(ll v, ll p, vector<bool> &visited, vector<ll> &tin, vector<ll> &low, vector<vector<pair<ll,ll>>> & adj, ll &timer, vector<pair<ll,ll>> &bridges) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (auto loa : adj[v]) {
        auto w = loa.first;
        if (w == p) continue;
        if (visited[w]) {
            low[v] = min(low[v], tin[w]);
        } else {
            dfs(w, v, visited, tin, low, adj, timer, bridges);
            low[v] = min(low[v], low[w]);
            if (low[w] > tin[v]) {
                bridges.push_back({v,w});
            }
        }
    }
}

vector<pair<ll,ll>> find_bridges(ll n, vector<vector<pair<ll,ll>>> &adj) {
    vector<pair<ll,ll>> bridges;
    ll timer = 0;
    vector<bool> visited(n,false);
    vector<ll> tin(n,-1), low(n,-1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i, -1, visited, tin, low, adj, timer,bridges);
    }
    return bridges;
}

vector<ll> get_shortest_path(ll n, vector<vector<pair<ll,ll>>> &graph) {
    vector<ll> distances(n,INF);
    distances[n-1] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,n-1});
    while(!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        debug(d)
        debug(u)
        if(d > distances[u]) continue;
        for(auto [v,w]: graph[u]) {
            if(distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                pq.push({distances[v],v});
            }
        }
    }
    return distances;
}

int main()
{
    fastio();
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n,m,k;
        cin >> n >> m >> k;
        vector<ll> a(n);
        for(ll i=0;i<n;i++)
            cin >> a[i];
        vector<vector<pair<ll,ll>>> graph(n);
        for(ll i=0;i<m;i++)
        {
            ll u,v,d;
            cin >> u >> v >> d;
            u--,v--;
            graph[u].push_back({v,d});
            graph[v].push_back({u,d});
        }
        vector<pair<ll,ll>> bridges = find_bridges(n,graph);
        for(auto x:bridges) {
            for(auto y: graph[x.first]) {
                if(y.first == x.second) {
                    auto it = find(graph[x.first].begin(),graph[x.first].end(),y);
                    graph[x.first].erase(it);
                }
            }
            for(auto y: graph[x.second]) {
                if(y.first == x.first) {
                    auto it = find(graph[x.second].begin(),graph[x.second].end(),y);
                    graph[x.second].erase(it);
                }
            }
        }
        vector<ll> b(n);
        for(ll i = 0;i < n;i++) {
            if(graph[i].size() >= k) {
                b[i] = 1;
            } else {
                b[i] = 0;
            }
        }
        vector<pair<ll,ll>> extra_node;
        for(ll i = 0; i < n;i++) {
            if(b[i] == 1) {
                graph[i].push_back({n,0});
                extra_node.push_back({i,0});
            }
        }
        graph.push_back(extra_node);
        debug(graph)
        vector<ll> distances = get_shortest_path(n+1,graph);
        debug(distances)
        ll ans1,ans2;
        for(ll i = 0; i < n;i++) {
            if(distances[i] == INF) {
                ans2+=a[i];
            } else {
                ans1+=distances[i];
            }
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}