#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll modulo = 1000000007;

struct matrix
{
    ll mat[4][4];
    matrix friend operator*(const matrix &a, const matrix &b)
    {
        matrix c;
        for (ll i = 0; i < 4; i++)
        {
            for (ll j = 0; j < 4; j++)
            {
                c.mat[i][j] = 0;
                for (int k = 0; k < 4; k++)
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
    matrix ans{{{1, 0, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1}}};
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
        ll a, b, c, d, t1, t2, t3, n;
        cin >> a >> b >> c >> d >> t1 >> t2 >> t3 >> n;
        if (n == 1)
        {
            cout << t1 << endl;
            continue;
        }
        else if (n == 2)
        {
            cout << t2 << endl;
            continue;
        }
        else if (n == 3)
        {
            cout << t3 << endl;
            continue;
        }
        matrix base{{{a, b, c, d},
                     {1, 0, 0, 0},
                     {0, 1, 0, 0},
                     {0, 0, 0, 1}}};
        matrix ans = matpow(base, n - 3);
        ll res = ((ans.mat[0][0] * t3) % modulo + (ans.mat[0][1] * t2) % modulo + (ans.mat[0][2] * t1) % modulo + (ans.mat[0][3] * 1) % modulo) % modulo;
        cout << res << endl;
    }
}