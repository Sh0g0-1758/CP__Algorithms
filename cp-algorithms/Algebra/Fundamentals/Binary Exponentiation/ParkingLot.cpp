#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long ans = 0;
    long long k = 0;
    while (k <= n - 2)
    {
        if (k == 0)
        {
            if (n - 3 == 0)
            {
                ans += 4 * 3;
            }
            else
            {
                ans += 4 * 3 * (pow(4, (n - 3)));
            }
        }
        else if (k != n - 2)
        {
            if (k - 1 == 0)
            {
                if (n - 3 - k == 0)
                {
                    ans += 3 * 4 * 3;
                }
                else
                {
                    ans += 3 * 4 * 3 * (pow(4, (n - 3 - k)));
                }
            }
            else
            {
                if (n - 3 - k == 0)
                {
                    ans += (pow(4, (k - 1))) * 3 * 4 * 3;
                }
                else
                {
                    ans += (pow(4, (k - 1))) * 3 * 4 * 3 * (pow(4, (n - 3 - k)));
                }
            }
        }
        else
        {
            if (k - 1 == 0)
            {
                ans += 3 * 4;
            }
            else
            {
                ans += (pow(4, (k - 1))) * 3 * 4;
            }
        }
        k++;
    }
    cout << ans << endl;
}
