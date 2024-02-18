// All complex things are inherently simple. If you can't explain something simply, you just don't understand it well enough.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll modulo = 1000000007;

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
        if (n == 1)
        {
            cout << 4 << endl;
            continue;
        }
        else if (n == 2)
        {
            cout << 16 << endl;
            continue;
        }
        else if (n == 3)
        {
            cout << 48 << endl;
            continue;
        }
        else if (n == 4)
        {
            cout << 136 << endl;
            continue;
        }
        matrix base = {{{1, 4, 4},
                        {1, 0, 0},
                        {0, 1, 0}}};
        matrix ans = matpow(base, n - 4);
        cout << (ans.mat[0][0] * 136 + ans.mat[0][1] * 48 + ans.mat[0][2] * 16) % modulo << endl;
    }
    return 0;
}