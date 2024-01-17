#include <bits/stdc++.h>
using namespace std;

int gcd_pair(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd_pair(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    int a, b, c, x1, x2, y1, y2, x, y;
    cin >> a >> b >> c;
    cin >> x1 >> x2 >> y1 >> y2;
    a *= -1;
    b *= -1;
    int g = gcd_pair(abs(a), abs(b), x, y);
    if (c % g != 0)
    {
        return 0;
    }
    x *= c / g;
    y *= c / g;
    if (a < 0)
        x *= -1;
    if (b < 0)
        y *= -1;
    int x_k_min = (x1 - x) / abs(b);
    int x_k_max = (x2 - x) / abs(b);
    int y_k_min = (y - y2) / abs(a);
    int y_k_max = (y - y1) / abs(a);
    int lower_bound = max(x_k_min, y_k_min);
    int upper_bound = min(x_k_max, y_k_max);
    cout << upper_bound - lower_bound + 1 << "\n";
}