#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int> &coinList, int value)
{
    int n = coinList.size();
    int coins[value + 1];

    if (value == 0)
        return 0;
    coins[0] = 0;

    for (int i = 1; i <= value; i++)
        coins[i] = INT_MAX;

    for (int i = 1; i <= value; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coinList[j] <= i)
            {
                int tempCoins = coins[i - coinList[j]];
                if (tempCoins != INT_MAX && tempCoins + 1 < coins[i])
                    coins[i] = tempCoins + 1;
            }
        }
    }
    return coins[value];
}

int main()
{
    vector<int> coinList = {1, 5, 10, 25};
    int value = 16;

    cout << minCoins(coinList, value);

    return 0;
}