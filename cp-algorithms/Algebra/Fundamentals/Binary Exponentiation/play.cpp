#include <iostream>
using namespace std;

long long binpow(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
    { // goes in when b is odd.
        cout << "b : " << b << endl;
        cout << "res : " << res << endl;
        return res * res * a;
    }
    else
    {
        return res * res;
    }
}

long long fast_binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << binpow(a, b) << endl;
    return 0;
}