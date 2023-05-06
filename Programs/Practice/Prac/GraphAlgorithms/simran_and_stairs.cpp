#include <bits/stdc++.h>
using namespace std;
int countStairs(int n)
{

    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    if (n == 1)
        return dp[1];
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    return dp[n];
}
int main()
{
    int n = 4;

    int res = 0;
    res = countStairs(n);
    cout << res << "\n";
    return 0;
}