// All complex things are inherently simple. If you can't explain something simply, you just don't understand it well enough.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<vector<ll>> q(n, vector<ll>(m));
        vector<vector<ll>> p(n, vector<ll>(m));
        for (auto &it : q)
        {
            for (auto &i : it)
            {
                cin >> i;
            }
        }
        ll ans = INT_MIN;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (i + j > k)
                {
                    break;
                }
                if (i == 0 && j == 0)
                {
                    p[i][j] = q[i][j];
                }
                else if (i == 0)
                {
                    p[i][j] = p[i][j - 1] + q[i][j];
                }
                else if (j == 0)
                {
                    p[i][j] = p[i - 1][j] + q[i][j];
                }
                else
                {
                    p[i][j] = max(p[i - 1][j], p[i][j - 1]) + q[i][j];
                }
                ans = max(ans, p[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}