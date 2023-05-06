#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    vector<pair<int, int>> v;
    int n = prices.size();
    if (n == 0)
        return 0;
    int max1 = prices[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        max1 = max(max1, prices[i]);
        v.push_back({prices[i], max1});
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {

        if (v[i].second - v[i].first > res)
        {
            res = v[i].second - v[i].first;
        }
    }
    return res;
}

int main()

{
    vector<int> prices = {9, 11, 8, 5, 7, 10};

    cout << maxProfit(prices);

    return 0;
}

//Time Complexity: O(n)
//Space Complexity: O(n)