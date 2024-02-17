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
        string result;
        for (int i = 0; i < k; i++)
        {
            result += 'a' + i;
        }
        string temp = result;
        for (int i = 0; i < n - 1; i++)
        {
            result = result + temp;
        }
        cout << result << endl;
    }
    return 0;
}