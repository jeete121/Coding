#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
long long modInverse(long long c, long long m)
{
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
        return 0;

    while (c > 1)
    {
        long long q = c / m;
        long long t = m;
        m = c % m;
        c = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;

    return x;
}
int main()
{
    long long n = 3;

    long long arr[n] = {1, 2, 4};

    long long x = arr[0];
    long long brr[n];
    brr[0] = 1;
    long long ans = 0;
    for (long long i = 1; i < n; i++)
    {
        long long x = (arr[i] * modInverse(arr[i - 1], MOD)) % MOD;
        ans = (ans + ((x % MOD * (x + 1) % MOD) * modInverse(2, MOD))) % MOD;
    }
    ans = ((ans % MOD * (ans + 1) % MOD) % MOD * modInverse(2, MOD)) % MOD;
    cout << ans << "\n";

    return 0;
}