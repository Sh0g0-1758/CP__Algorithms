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
    cin >> t;
    while (t--)
    {
        ll n, m;
        m = 30000;
        cin >> n;
        vector<ll> array(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> array[i];
        }
        vector<ll> prev(m + 1, 0);
        vector<ll> next(m + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            next[array[i]]++;
        }
        ll result = 0;
        for (ll i = 0; i < n; i++)
        {
            next[array[i]]--;
            vector<ll> cnt = multiply(prev, next);
            result += cnt[2 * array[i]];
            prev[array[i]]++;
        }
        cout << result << endl;
    }
    return 0;
}