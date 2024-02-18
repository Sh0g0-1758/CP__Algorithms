#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long int mod = 1000000007;

ll binExp(ll a, ll b)
{
    ll ans = 1;

    a = a % mod;
    b = b % (mod - 1);

    if (a == 0)
    {
        return 0;
    }

    while (b)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % mod;
        b >>= 1;
        a = (a * 1LL * a) % mod;
    }

    return ans;
}

vector<vector<ll>> matMul(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
    vector<vector<ll>> c(3, vector<ll>(3, 0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return c;
}

vector<vector<ll>> matExp(vector<vector<ll>> a, ll N)
{
    if (N == 0)
    {
        return {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    }
    vector<vector<ll>> b = matExp(a, N / 2);
    b = matMul(b, b);
    if (N % 2)
        return matMul(b, a);
    return b;
}

void solve(ll n)
{
    ll total = binExp(2, n);

    vector<vector<ll>> a = {
        {1, 1, 1}, {1, 0, 0}, {0, 1, 0}};

    a = matExp(a, n - 2);

    ll non = ((4 * a[0][0]) % mod + ((2 * a[0][1]) % mod + a[0][2]) % mod) % mod;

    cout << (total - non + mod) % mod << endl;
}

int main()
{
    int t;
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

        solve(n);
    }
    return 0;
}
