#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<vector<int>> coins)
{
    int n = coins.size();

    int m = coins[0].size();

    int dp[n + 1][m + 1];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            //if we are in the first row
            if (i == 0)
            {
                dp[i][j] = dp[i][j] + coins[i][j];
            }

            //if we are in the first column
            else if (j == 0)
            {
                dp[i][j] = dp[i][j] + coins[i][j];
            }

            //else we take max of both
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + coins[i][j];
            }
        }
    }
    return dp[n - 1][m - 1];
}
int main()
{
    vector<vector<int>> coins = {{0, 3, 1, 1},
                                 {2, 0, 0, 4},
                                 {1, 5, 3, 1}};

    cout << maxCoins(coins);

    return 0;
}