#include <bits/stdc++.h>
using namespace std;

int dp[1000];

int countWays(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = countWays(n - 1) + countWays(n - 2);
    return dp[n];
}
int main()
{
    int n = 4;

    memset(dp, -1, sizeof(dp));
    cout << countWays(n);

    return 0;
}