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
        ll n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;
        vector<ll> v(k);
        for (int i = 0; i < m; i++)
        {
            v[s[i] - 97]++;
        }
        bool flag = true;
        ll pos = 0;
        for (int i = 0; i < k; i++)
        {
            if (v[i] < n)
            {
                flag = false;
                pos = i;
                break;
            }
        }
        if (flag)
        {
            vector<ll> v_another(k);
            ll count = 0;
            ll iter = 0;
            ll checkpoint = 0;
            for (int i = 0; i < m; i++)
            {
                while (accumulate(v_another.begin(), v_another.end(), 0) != (count + 1) * k)
                {
                    if (v_another[s[i] - 97] == count && iter == (s[i] - 97))
                    {
                        v_another[s[i] - 97]++;
                        iter++;
                    }
                    i++;
                    if (i >= m)
                    {
                        break;
                    }
                }
                iter = 0;
                if (i >= m)
                {
                    break;
                }
                count++;
                checkpoint = i;
            }
            vector<ll> v_yet_another(k);
            for (int i = checkpoint; i < m; i++)
            {
                if (v_yet_another[s[i] - 97] == 0)
                {
                    v_yet_another[s[i] - 97]++;
                }
            }
            bool flag = false;
            if (accumulate(v_yet_another.begin(), v_yet_another.end(), 0) == k)
            {
                flag = true;
            }
            if (count == n || (flag && count == n - 1))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
                string ans = "";
                if (count == 0)
                {
                    for (int i = 0; i < k; i++)
                    {
                        ans = ans + (char)(i + 97);
                    }
                }
                else
                {
                    ans = ans += char(k - 1 + 97);
                    for (int i = k - 2; i >= 0; i--)
                    {
                        ans = ans + (char)(97);
                    }
                }
                cout << ans << endl;
            }
        }
        else
        {
            cout << "NO " << endl;
            string ans = "";
            for (int i = 0; i < n; i++)
            {
                ans += (pos + 97);
            }
            cout << ans << endl;
        }
    }
    return 0;
}