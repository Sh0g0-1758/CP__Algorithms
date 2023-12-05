#include <cmath>

class Solution
{
public:
    int countGoodNumbers(long long n)
    {
        const int MOD = 1000000007;
        long long even = (n + 1) / 2;
        long long odd = n - even;

        long long evenPower = customPow(5, even, MOD);
        long long oddPower = customPow(4, odd, MOD);

        return (evenPower * oddPower) % MOD;
    }

private:
    long long customPow(long long base, long long exponent, int mod)
    {
        long long result = 1;
        while (exponent > 0)
        {
            if (exponent % 2 == 1)
            {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent /= 2;
        }
        return result;
    }
};