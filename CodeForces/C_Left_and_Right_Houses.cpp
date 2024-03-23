// All complex things are inherently simple. If you can't explain something simply,
// you just don't understand it well enough.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

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
        string s;
        cin >> s;
        vector<pair<ll, ll>> v(n+1, {0, 0});
        for(int i = 1; i <= n;i++) {
            if(s[i-1] == '0') {
                v[i].first = v[i-1].first + 1;
                v[i].second = v[i-1].second;
            } else {
                v[i].second = v[i-1].second + 1;
                v[i].first = v[i-1].first;
            }
        }
        v.push_back({v[n].first, v[n].second});
        ll ans = 0;
        ll cost = INT_MAX;
        for(int i = 0; i <= n;i++) {
            ll x = i / 2;
            if(i % 2) x++;
            ll y = (n-i) / 2;
            if((n-i) % 2) y++;
            if(v[i].first >= x && (v[n+1].second - v[i].second) >= y) {
                if(cost > abs((n/2.0) - i)) {
                    cost = abs((n/2.0) - i);
                    ans = i;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}