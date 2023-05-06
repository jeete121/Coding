#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
long long dp[100001];
void fact()
{

    dp[0] = 1;

    dp[1] = 1;
    for (long long i = 2; i <= 100000; i++)
        dp[i] = ((i) % MOD * (dp[i - 1]) % MOD) % MOD;
}
int main()
{

    long long n = 5;
    fact();
    long long ans = dp[n];
    cout << ans << "\n";

    return 0;
}