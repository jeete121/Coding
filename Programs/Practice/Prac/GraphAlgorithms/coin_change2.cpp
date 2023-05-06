#include <bits/stdc++.h>
using namespace std;

int change(int m, vector<int> &coins)
{
    int n = coins.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}

int main()
{
    int amount = 5;
    vector<int> coins = {1, 2, 5};

    cout << change(amount, coins);

    return 0;
}