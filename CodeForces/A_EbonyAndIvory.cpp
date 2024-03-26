#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long m, n, k, i, ans, d;
    cin >> m >> n >> k;
    ans = 0;
    for (int i = 0; i < 1000; i++)
    {
        d = (k - (m * i));
        if (d < 0)
        {
            ans = 0;
            break;
        }
        if (d % n == 0)
        {
            ans = 1;
            break;
        }
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}