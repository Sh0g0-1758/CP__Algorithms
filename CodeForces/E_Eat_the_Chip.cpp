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
        ll h, w, xa, ya, xb, yb;
        cin >> h >> w >> xa >> ya >> xb >> yb;
        string winner = "";
        if (abs(xa - xb) % 2 == 0)
        {
            if (xa >= xb)
            {
                winner = "Draw";
            }
            else if (ya == yb)
            {
                winner = "Bob";
            }
            else
            {
                ll n_turns = 0;
                if (ya < yb)
                {
                    n_turns = yb - 1;
                }
                else
                {
                    n_turns = w - yb;
                }
                if (xb - 2 * n_turns >= xa)
                {
                    winner = "Bob";
                }
                else
                {
                    winner = "Draw";
                }
            }
        }
        else
        {
            xa += 1;
            if (yb > ya)
            {
                ya += 1;
            }
            else if (yb < ya)
            {
                ya -= 1;
            }
            if (xa > xb)
            {
                winner = "Draw";
            }
            else if (ya == yb)
            {
                winner = "Alice";
            }
            else
            {
                ll n_turns = 0;
                if (ya < yb)
                {
                    n_turns = w - ya;
                }
                else
                {
                    n_turns = ya - 1;
                }
                if (xb - 2 * n_turns >= xa)
                {
                    winner = "Alice";
                }
                else
                {
                    winner = "Draw";
                }
            }
        }
        cout << winner << endl;
    }
    return 0;
}