#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    vector<double> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {

        for (auto coin : coins)
        {

            if (coin <= i)
            {

                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp.back() == INT_MAX ? -1 : dp.back();
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << coinChange(coins, amount);

    return 0;
}