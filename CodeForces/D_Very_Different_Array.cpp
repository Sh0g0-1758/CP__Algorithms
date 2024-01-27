#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(m);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll cnt1 = 0;
        ll cnt2 = n - 1;
        ll cnt3 = 0;
        ll cnt4 = m - 1;
        ll D = 0;
        while (cnt1 <= cnt2)
        {
            ll first = abs(a[cnt1] - b[cnt3]);
            ll second = abs(a[cnt2] - b[cnt3]);
            ll third = abs(a[cnt1] - b[cnt4]);
            ll fourth = abs(a[cnt2] - b[cnt4]);
            ll max_to_add = max(first, max(second, max(third, fourth)));
            if (max_to_add == first)
            {
                D += first;
                cnt1++;
                cnt3++;
            }
            else if (max_to_add == second)
            {
                D += second;
                cnt2--;
                cnt3++;
            }
            else if (max_to_add == third)
            {
                D += third;
                cnt1++;
                cnt4--;
            }
            else
            {
                D += fourth;
                cnt2--;
                cnt4--;
            }
        }
        cout << D << endl;
    }
}