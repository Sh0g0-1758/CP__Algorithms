// All complex things are inherently simple. If you can't explain something simply, you just don't understand it well enough.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

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
    t = 1;
    // cin >> t;
    while (t--)
    {
        ll sa, sb, sc, sd, k;
        cin >> sa >> sb >> sc >> sd >> k;
        vector<ll> a, b, c, d;
        for (ll i = 0; i < sa; i++)
        {
            ll x;
            cin >> x;
            a.push_back(x);
        }
        for (ll i = 0; i < sb; i++)
        {
            ll x;
            cin >> x;
            b.push_back(x);
        }
        for (ll i = 0; i < sc; i++)
        {
            ll x;
            cin >> x;
            c.push_back(x);
        }
        for (ll i = 0; i < sd; i++)
        {
            ll x;
            cin >> x;
            d.push_back(x);
        }
        ll m_a = *max_element(a.begin(), a.end());
        vector<ll> _a(m_a + 1, 0);
        for (ll i = 0; i < sa; i++)
            _a[a[i]]++;
        ll m_b = *max_element(b.begin(), b.end());
        vector<ll> _b(m_b + 1, 0);
        for (ll i = 0; i < sb; i++)
            _b[b[i]]++;
        ll m_c = *max_element(c.begin(), c.end());
        vector<ll> _c(m_c + 1, 0);
        for (ll i = 0; i < sc; i++)
            _c[c[i]]++;
        ll m_d = *max_element(d.begin(), d.end());
        vector<ll> _d(m_d + 1, 0);
        for (ll i = 0; i < sd; i++)
            _d[d[i]]++;
        vector<ll> res1 = multiply(_a, _b);
        vector<ll> res2 = multiply(_c, _d);
        vector<ll> pre_sum_res2;
        for (ll i = 0; i < res2.size(); i++)
        {
            if (i == 0)
                pre_sum_res2.push_back(res2[i]);
            else
                pre_sum_res2.push_back(pre_sum_res2[i - 1] + res2[i]);
        }

        ll n = pre_sum_res2.size();
        ll lo = 0, hi = 5e10;

        while (lo < hi)
        {
            ll mid = (lo + hi) >> 1;
            ll cnt = 0;
            ll p1 = 0, p2 = n - 1;
            while (p2 >= 0)
            {
                while (p1 < n && p1 * p2 <= mid)
                    p1++;
                cnt += res1[p2] * (p1 > 0 ? pre_sum_res2[p1 - 1] : 0);
                p2--;
            }

            if (cnt < k)
                lo = mid + 1;
            else
                hi = mid;
        }

        cout << hi << endl;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}