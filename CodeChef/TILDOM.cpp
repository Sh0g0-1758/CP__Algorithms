#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll modulo = 1000000007;

struct matrix
{
    ll mat[2][2];
    matrix friend operator*(const matrix &a, const matrix &b)
    {
        matrix c;
        for (ll i = 0; i < 2; i++)
        {
            for (ll j = 0; j < 2; j++)
            {
                c.mat[i][j] = 0;
                for (int k = 0; k < 2; k++)
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
    matrix ans{{
        {1, 0},
        {0, 1},
    }};
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 0)
        {
            cout << 1 << endl;
            continue;
        }
        else if (n == 1)
        {
            cout << 3 << endl;
            continue;
        }
        matrix base = {{{3, 2},
                        {1, 0}}};
        matrix ans = matpow(base, n - 1);
        ll res = ((ans.mat[0][0] * 3) % modulo + (ans.mat[0][1] * 1) % modulo) % modulo;
        cout << res << endl;
    }
}