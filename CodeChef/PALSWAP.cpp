#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll merge(vector<ll> &a, ll start, ll mid, ll end)
{
    vector<ll> b;
    vector<ll> c;
    for (ll i = 0; i < mid - start + 1; i++)
    {
        b.push_back(a[start + i]);
    }
    for (ll i = 0; i < end - mid; i++)
    {
        c.push_back(a[mid + 1 + i]);
    }
    ll index_1 = 0;
    ll index_2 = 0;
    ll index_3 = start;
    ll ans = 0;
    while (index_1 < mid - start + 1 && index_2 < end - mid)
    {
        if (b[index_1] <= c[index_2])
        {
            a[index_3] = b[index_1];
            index_1++;
        }
        else
        {
            a[index_3] = c[index_2];
            index_2++;
            ans += mid - start + 1 - index_1;
        }
        index_3++;
    }
    while (index_1 < mid - start + 1)
    {
        a[index_3] = b[index_1];
        index_1++;
        index_3++;
    }
    while (index_2 < end - mid)
    {
        a[index_3] = c[index_2];
        index_2++;
        index_3++;
    }
    return ans;
}

ll inversions_from_merge(vector<ll> &a, ll start, ll end)
{
    if (start >= end)
    {
        return 0;
    }
    ll mid = start + (end - start) / 2;
    ll b = inversions_from_merge(a, start, mid);
    ll c = inversions_from_merge(a, mid + 1, end);
    ll d = merge(a, start, mid, end);
    return b + c + d;
}

ll count_inversions(string s1, string s2, int m)
{
    vector<vector<ll>> a(26);
    for (ll i = 0; i < m; i++)
    {
        a[s1[i] - 'a'].push_back(i);
    }
    vector<ll> b;
    for (ll i = 0; i < m; i++)
    {
        ll temp = a[s2[i] - 'a'].size();
        if (temp == 0)
        {
            return -1;
        }
        b.push_back(a[s2[i] - 'a'].front());
        a[s2[i] - 'a'].erase(a[s2[i] - 'a'].begin());
    }
    return inversions_from_merge(b, 0, m - 1);
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
        cin >> n >> m;
        vector<string> s(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        vector<string> col;
        for (ll i = 0; i < m; i++)
        {
            string temp = "";
            for (ll j = 0; j < n; j++)
            {
                temp += s[j][i];
            }
            col.push_back(temp);
        }
        ll ans = 0;
        for (ll i = 0; i < m / 2; i++)
        {
            ll temp_ans = count_inversions(col[i], col[m - 1 - i], n);
            if (temp_ans == -1)
            {
                ans = -1;
                break;
            }
            else
            {
                ans += temp_ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}