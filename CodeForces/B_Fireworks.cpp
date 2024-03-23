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
        ll a,b,m;
        cin >> a >> b >> m;
        cout << m/a + m/b + 2 << endl;
    }
    return 0;
}