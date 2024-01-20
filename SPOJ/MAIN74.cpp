#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll modulo = 1000000007;

// Use Lames theorem which states that for a certain number n representing the number of divisions in euclid algorithm, the least numbers which can get that is the Fibo Sequence. 

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

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        matrix base = {{
            {1, 1},
            {1, 0},
        }};
        ll first = 0, second = 0;
        if (n == 0) {
            first = 0;
            second = 0;
        } else if (n == 1) {
            first = 1;
            second = 1;
        } else {
            matrix f_mat = matpow(base, n - 1);
            matrix s_mat = matpow(base, n);
            first = (f_mat.mat[0][0] + f_mat.mat[0][1]) % modulo;
            second = (s_mat.mat[0][0] + s_mat.mat[0][1]) % modulo;
        }
        cout << (second + first) % modulo << endl;
    }
}