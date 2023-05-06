#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long chargeArray(long long n, long long a[])
{
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] >= pow(2, n) / 2)
        {
            ans = (ans + a[i]) % MOD;
        }
    }
    return ans % MOD;
}
int main()
{

    long long n = 3;
    long long a[n] = {3, 4, 5};

    cout << chargeArray(n, a) << "\n";

    return 0;
}