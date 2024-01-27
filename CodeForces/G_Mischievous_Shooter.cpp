#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

bool prov(int i, int j, int n, int m)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}

ll no_rotate(ll n, ll m, ll k, ll *field)
{
    ll local_field[n][m];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            local_field[i][j] = *(field + i * m + j);
        }
    }
    ll dp[n][m];
    ll ans = 0;
    int pref[n][m];
    int pref_up[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pref_up[i][j] = local_field[i][j];
            if (prov(i - 1, j, n, m))
                pref_up[i][j] += pref_up[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            pref[i][j] = local_field[i][j];
            if (prov(i - 1, j + 1, n, m))
                pref[i][j] += pref[i - 1][j + 1];
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            dp[i][j] = pref_up[i][j];
            if (prov(i - k, j, n, m))
                dp[i][j] -= pref_up[i - k][j];
            if (prov(i, j - 1, n, m))
                dp[i][j] += dp[i][j - 1];
            if (j < k)
            {
                int i1 = j - k + i;
                if (i1 >= 0)
                    dp[i][j] -= pref[i1][0];
            }
            else
                dp[i][j] -= pref[i][j - k];
            if (prov(i - k, j, n, m))
                dp[i][j] += pref[i - k][j];
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

ll rotate_r(ll n, ll m, ll k, ll *field)
{
    ll local_field[m][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            local_field[j][n - i - 1] = *(field + i * m + j);
        }
    }
    swap(n, m);
    ll dp[n][m];
    ll ans = 0;
    int pref[n][m];
    int pref_up[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pref_up[i][j] = local_field[i][j];
            if (prov(i - 1, j, n, m))
                pref_up[i][j] += pref_up[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            pref[i][j] = local_field[i][j];
            if (prov(i - 1, j + 1, n, m))
                pref[i][j] += pref[i - 1][j + 1];
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            dp[i][j] = pref_up[i][j];
            if (prov(i - k, j, n, m))
                dp[i][j] -= pref_up[i - k][j];
            if (prov(i, j - 1, n, m))
                dp[i][j] += dp[i][j - 1];
            if (j < k)
            {
                int i1 = j - k + i;
                if (i1 >= 0)
                    dp[i][j] -= pref[i1][0];
            }
            else
                dp[i][j] -= pref[i][j - k];
            if (prov(i - k, j, n, m))
                dp[i][j] += pref[i - k][j];
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

ll rotate_l(ll n, ll m, ll k, ll *field)
{
    ll local_field[m][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            local_field[m - j - 1][i] = *(field + i * m + j);
        }
    }
    swap(n, m);
    ll dp[n][m];
    ll ans = 0;
    int pref[n][m];
    int pref_up[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pref_up[i][j] = local_field[i][j];
            if (prov(i - 1, j, n, m))
                pref_up[i][j] += pref_up[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            pref[i][j] = local_field[i][j];
            if (prov(i - 1, j + 1, n, m))
                pref[i][j] += pref[i - 1][j + 1];
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            dp[i][j] = pref_up[i][j];
            if (prov(i - k, j, n, m))
                dp[i][j] -= pref_up[i - k][j];
            if (prov(i, j - 1, n, m))
                dp[i][j] += dp[i][j - 1];
            if (j < k)
            {
                int i1 = j - k + i;
                if (i1 >= 0)
                    dp[i][j] -= pref[i1][0];
            }
            else
                dp[i][j] -= pref[i][j - k];
            if (prov(i - k, j, n, m))
                dp[i][j] += pref[i - k][j];
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

ll rotate_b(ll n, ll m, ll k, ll *field)
{
    ll local_field[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            local_field[n - i - 1][m - j - 1] = *(field + i * m + j);
        }
    }
    ll dp[n][m];
    ll ans = 0;
    int pref[n][m];
    int pref_up[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pref_up[i][j] = local_field[i][j];
            if (prov(i - 1, j, n, m))
                pref_up[i][j] += pref_up[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            pref[i][j] = local_field[i][j];
            if (prov(i - 1, j + 1, n, m))
                pref[i][j] += pref[i - 1][j + 1];
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            dp[i][j] = pref_up[i][j];
            if (prov(i - k, j, n, m))
                dp[i][j] -= pref_up[i - k][j];
            if (prov(i, j - 1, n, m))
                dp[i][j] += dp[i][j - 1];
            if (j < k)
            {
                int i1 = j - k + i;
                if (i1 >= 0)
                    dp[i][j] -= pref[i1][0];
            }
            else
                dp[i][j] -= pref[i][j - k];
            if (prov(i - k, j, n, m))
                dp[i][j] += pref[i - k][j];
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

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
        ll field[n][m];
        for (ll i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (ll j = 0; j < m; j++)
            {
                if (s[j] == '#')
                {
                    field[i][j] = 1;
                }
                else
                {
                    field[i][j] = 0;
                }
            }
        }
        ll ans1 = no_rotate(n, m, k, (ll *)field);
        ll ans2 = rotate_r(n, m, k, (ll *)field);
        ll ans3 = rotate_l(n, m, k, (ll *)field);
        ll ans4 = rotate_b(n, m, k, (ll *)field);
        cout << max(ans1, max(ans2, max(ans3, ans4))) << endl;
    }
    return 0;
}