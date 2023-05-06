#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
long long fact(long long n)
{
    long long dp[n + 1];
    if (n == 1)
        return 1;
    dp[1] = 1;
    for (long long i = 2; i <= n; i++)
        dp[i] = ((i % MOD) * (dp[i - 1] % MOD)) % MOD;
    return dp[n] % MOD;
}
int main()
{
    long long n = 2, m = 2;

    long long res;
    res = fact(m);
    cout << res << "\n";
    return 0;
}