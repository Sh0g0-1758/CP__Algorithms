// All complex things are inherently simple. If you can't explain something simply, you just don't understand it well enough.

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
        ll N, X, Y, Z;
        cin >> N >> X >> Y >> Z;
        vector<ll> A(N);
        for (ll i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        vector<bitset<1515>> dp(X + 1);
        dp[0][0] = 1;
        bitset<1515> y(0);
        ll SUM = 0;
        for (int i = 0; i <= Y; i++)
        {
            y[i] = 1;
        }
        ll ans = N;
        for (ll i = 0; i < N; i++)
        {
            ll exist = 0;
            SUM += A[i];
            for (ll x = X; x >= 0; x--)
            {
                ll k = 0;
                if (SUM - x - Z > 0)
                {
                    k = SUM - x - Z;
                }
                if (x - A[i] >= 0)
                {
                    dp[x] = (((dp[x] >> k) << k) | (dp[x] << A[i]) | (dp[x - A[i]])) & y;
                }
                else
                {
                    dp[x] = (((dp[x] >> k) << k) | (dp[x] << A[i])) & y;
                }
                exist |= dp[x].any();
            }
            if (!exist)
            {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}