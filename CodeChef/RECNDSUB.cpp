// All complex things are inherently simple. If you can't explain something simply, you just don't understand it well enough.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define mod 163577857

ll power(ll x, ll y)
{
    ll i, power = 1;
    if (y == 0)
        return 1;
    for (i = 1; i <= y; i++)
        power = power * x;
    return power;
}

ll NcR(int n, int r)
{
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
    {
        p = 1;
    }
    return p;
}

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert)
{
    ll n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (ll i = 0; 2 * i < n; i++)
    {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (ll i = 0; 2 * i < n; i++)
    {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert)
        {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

vector<ll> multiply(vector<ll> const &a, vector<ll> const &b)
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (ll i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
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
        vector<ll> s;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            s.push_back(x);
        }
        ll c_1 = 0;
        ll c0 = 0;
        ll c1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == -1)
            {
                c_1++;
            }
            else if (s[i] == 0)
            {
                c0++;
            }
            else
            {
                c1++;
            }
        }
        ll val0 = power(2, c0);
        vector<ll> val_1;
        vector<ll> val1;
        for (int i = 0; i <= c_1; i++)
        {
            val_1.push_back(NcR(c_1, i));
        }
        for (int i = 0; i <= c1; i++)
        {
            val1.push_back(NcR(c1, i));
        }
        if (c_1 < c1)
        {
            while (val_1.size() != val1.size())
            {
                val_1.push_back(0);
            }
            reverse(val_1.begin(), val_1.end());
        }
        else
        {
            while (val1.size() != val_1.size())
            {
                val1.push_back(0);
            }
            reverse(val1.begin(), val1.end());
        }
        vector<ll> raw_ans = multiply(val_1, val1);
        vector<ll> ans;
        for (auto it : raw_ans)
        {
            if (it != 0)
            {
                ans.push_back(it);
            }
        }
        for (int i = 0; i < n - c1; i++)
        {
            ans.push_back(0);
        }
        for (int i = 0; i < n - c_1; i++)
        {
            ans.insert(ans.begin(), 0);
        }
        for (ll i = 0; i < ans.size(); i++)
        {
            if (i == n)
            {
                cout << ((ans[i] * val0) % mod) - 1 << " ";
            }
            else
            {
                cout << (ans[i] * val0) % mod << " ";
            }
        }
        cout << endl;
    }
    return 0;
}