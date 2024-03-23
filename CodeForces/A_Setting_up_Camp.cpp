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
        ll a,b,c;
        cin >> a >> b >> c;
        ll camp_b = b / 3;
        ll rem_b = b - (3 * camp_b);
        if(rem_b != 0) {
            camp_b++;
        } else {
            rem_b = 3;
        }
        ll req_c = 3 - rem_b;
        ll rem_c = c - req_c;
        ll camp_c = rem_c / 3;
        if(rem_c % 3 != 0) {
            camp_c++;
        }
        if (req_c <= c) {
            cout << a + camp_b + camp_c << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}