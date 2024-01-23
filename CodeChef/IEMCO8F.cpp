#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll modulo = 1000000007;

struct matrix
{
    ll mat[5][5];
    matrix friend operator*(const matrix &a, const matrix &b)

    {
        matrix c;
        for (ll i = 0; i < 5; i++)
        {
            for (ll j = 0; j < 5; j++)
            {
                c.mat[i][j] = 0;
                for (int k = 0; k < 5; k++)
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
    matrix ans{{{1, 0, 0, 0, 0},
                {0, 1, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 1, 0},
                {0, 0, 0, 0, 1}}};
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
        ll a, b, c, d, e, n;
        cin >> a >> b >> c >> d >> e >> n;
        if(n == 4) {
            cout << 3 << endl;
            continue;
        } else if (n == 3) {
            cout << 2 << endl;
            continue;
        } else if (n == 2) {
            cout << 1 << endl;
            continue;
        } else if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        matrix base{{{a, b, c, d, e},
                     {1, 0, 0, 0, 0},
                     {0, 1, 0, 0, 0},
                     {0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 1}}};
        matrix ans = matpow(base, n - 4);
        ll res = (ans.mat[0][0]*3 + ans.mat[0][1] * 2 + ans.mat[0][2] * 1 + ans.mat[0][3] * 0 + ans.mat[0][4]) % modulo;
        cout << res << endl;
    }
}