// All complex things are inherently simple. If you can't explain something simply,
// you just don't understand it well enough.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll modulo = 1000000007;

ll power_func(ll a, ll b)
{
    ll ans = 1;

    a = a % modulo;
    b = b % (modulo - 1);

    if (a == 0)
    {
        return 0;
    }

    while (b)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % modulo;
        b >>= 1;
        a = (a * 1LL * a) % modulo;
    }

    return ans;
}

struct matrix
{
    ll mat[3][3];
    matrix friend operator*(const matrix &a, const matrix &b)
    {
        matrix c;
        for (ll i = 0; i < 3; i++)
        {
            for (ll j = 0; j < 3; j++)
            {
                c.mat[i][j] = 0;
                for (int k = 0; k < 3; k++)
                {
                    c.mat[i][j] = (((a.mat[i][k] * b.mat[k][j]) % modulo) + c.mat[i][j]) % modulo;
                }
            }
        }
        return c;
    }
};

matrix matpow(matrix base, ll n)
{
    matrix ans{{{1, 0, 0},
                {0, 1, 0},
                {0, 0, 1}}};
    while (n)
    {
        if (n & 1)
            ans = ans * base;
        base = base * base;
        n >>= 1;
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
        ll n;
        cin >> n;
        if (n == 0 || n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        matrix base = {{{1, 1, 1},
                        {1, 0, 0},
                        {0, 1, 0}}};
        ll total = power_func(2, n);
        matrix ans = matpow(base, n - 2);
        ll res = ((ans.mat[0][0] * 4) % modulo + (ans.mat[0][1] * 2) % modulo + (ans.mat[0][2]) % modulo) % modulo;
        cout << (total - res + modulo) % modulo << endl;
    }
    return 0;
}