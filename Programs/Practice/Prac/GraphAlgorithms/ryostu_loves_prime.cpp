#include <bits/stdc++.h>
using namespace std;

bool dp[1000001];

void primeInitialize()
{
    memset(dp, true, sizeof(dp));
    dp[0] = false;
    dp[1] = false;
    for (long long i = 2; i * i <= 1000001; i++)
    {
        if (dp[i])
        {
            for (long long j = i * i; j <= 1000001; j += i)
                dp[j] = false;
        }
    }
}
long long sumOfEveryKthPrime(long long n,
                             long long k,
                             long long a[])
{

    long long cnt = 0;
    long long res = 0;
    for (long long i = 0; i < n; i++)
    {
        if (dp[a[i]])
            cnt++;
        if (cnt == k)
        {
            cnt = 0;
            res += a[i];
        }
    }
    return res;
}
int main()
{

    primeInitialize();
    long long n = 7, k = 2;

    long long a[n] = {1, 2, 13, 3, 5, 6, 7};

    cout << sumOfEveryKthPrime(n, k, a) << "\n";

    return 0;
}