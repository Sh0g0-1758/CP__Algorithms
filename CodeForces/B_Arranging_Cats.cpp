#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        string s1;
        string s2;
        cin >> n >> s1 >> s2;
        ll cnt1, cnt2;
        cnt1 = 0;
        cnt2 = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s1[i] == '1' && s2[i] == '0')
            {
                cnt1++;
            }
            else if (s1[i] == '0' && s2[i] == '1')
            {
                cnt2++;
            }
        }
        cout << max(cnt1, cnt2) << endl;
    }
}