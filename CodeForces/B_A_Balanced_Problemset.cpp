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
        ll n, k;
        cin >> n >> k;
        ll ans = n / k;
        while (ans > 1)
        {
            ll rem = n - (ans * (k - 1));
            if (rem % ans == 0)
            {
                break;
            }
            else
            {
                ans--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}