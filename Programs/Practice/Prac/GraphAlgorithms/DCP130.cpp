#include <bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int> &prices)
{
    if (prices.empty())
        return 0;
    int n = prices.size();
    vector<vector<int>> dp(k + 1,
                           vector<int>(n, 0));
    for (int i = 1; i <= k; i++)
    {
        int maximumValue = INT_MIN;
        for (int d = 1; d < n; d++)
        {
            maximumValue = max(maximumValue,
                               dp[i - 1][d - 1] - prices[d - 1]);
            dp[i][d] = max(dp[i][d - 1],
                           maximumValue + prices[d]);
        }
    }
    return dp[k].back();
}

int main()
{
    int k = 2;
    vector<int> prices = {5, 2, 4, 0, 1};

    cout << maxProfit(k, prices);

    return 0;
}