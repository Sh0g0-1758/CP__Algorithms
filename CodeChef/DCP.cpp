// All complex things are inherently simple. If you can't explain something simply, you just don't understand it well enough.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        ll m, n;
        cin >> n >> m;
        vector<ll> q;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            q.push_back(x);
        }
        for (ll i = 0; i < m; i++)
        {
            ll x, num;
            cin >> x >> num;
            for (ll j = 0; j < num; j++)
            {
                ll coeff, index;
                cin >> coeff >> index;
                q[index - 1] = (q[index - 1] + q[x - 1] * coeff) % mod;
            }
            q[x - 1] = 0;
        }
        for (auto it : q)
        {
            cout << it << endl;
        }
    }
    return 0;
}