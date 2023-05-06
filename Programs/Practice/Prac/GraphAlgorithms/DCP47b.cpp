#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int i = 1;
    if (prices.size() == 0)
        return 0;
    int buy, profit, sell, j;
    while (i < prices.size())
    {
        if (prices[i] < prices[i - 1])
            i++;
        else
        {
            j = i;
            break;
        }
    }
    if (i == prices.size())
        return 0;
    else
    {
        buy = prices[i - 1];
        sell = prices[j];
        profit = sell - buy;
        for (i = j + 1; i < prices.size(); i++)
        {
            if (prices[i] > sell)
            {
                sell = prices[i];
                if (sell - buy > profit)
                    profit = sell - buy;
            }
            else if (prices[i] < buy)
            {
                buy = prices[i];
                sell = prices[i];
            }
        }
    }
    return profit;
}
int main()

{
    vector<int> prices = {9, 11, 8, 5, 7, 10};

    cout << maxProfit(prices);

    return 0;
}

//Time Complexity: O(n)
//Space Complexity: O(1)