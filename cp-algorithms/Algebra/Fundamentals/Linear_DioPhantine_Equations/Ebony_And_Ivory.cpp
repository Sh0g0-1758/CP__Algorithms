#include <bits/stdc++.h>
using namespace std;

// int gcd_pair(int a, int b, int &x, int &y)
// {
//     if (b == 0)
//     {
//         x = 1;
//         y = 0;
//         return a;
//     }
//     int x1, y1;
//     int d = gcd_pair(b, a % b, x1, y1);
//     x = y1;
//     y = x1 - y1 * (a / b);
//     return d;
// }

// int main() {
//     int a,b,c;
//     cin >> a >> b >> c;
//     int u,v;
//     int g = gcd_pair(a,b,u,v);
//     cout << u << " " << v << "\n";
//     if (u * c % g != 0) {
//         cout << "No\n";
//         return 0;
//     }
//     if (v * c % g != 0) {
//         cout << "No\n";
//         return 0;
//     }
//     int x = u * c / g;
//     int y = v * c / g;
//     cout << x << " " << y << "\n";
//     if(x >= 0 && y >= 0) {
//         cout << "Yes\n";
//     } else if (x < 0 && y < 0) {
//         cout << "No\n";
//     } else {
//         if(x < 0) {
//             int k = abs(x) / b;
//             x += k * b;
//             y -= k * a;
//             if(x < 0) {
//                 x += b;
//                 y -= a;
//             }
//         } else {
//             cout << "Hello" << "\n";
//             int k = abs(y) / a;
//             cout << k << "\n";
//             x -= k * b;
//             y += k * a;
//             cout << x << " " << y << "\n";
//             if(y < 0) {
//                 x -= b;
//                 y += a;
//             }
//             cout << x << " " << y << "\n";
//         }
//         if(x < 0 || y < 0) {
//             cout << "No\n";
//         } else {
//             cout << "Yes\n";
//         }
//     }
// }

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