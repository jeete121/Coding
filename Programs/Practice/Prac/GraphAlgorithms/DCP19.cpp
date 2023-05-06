#include <bits/stdc++.h>
using namespace std;

int minCostHouseColor(vector<vector<int>> costs)
{
    if (costs.size() == 0)
        return 0;

    //find the value of n
    int n = costs.size();

    //find value of x
    int k = costs[0].size();

    //initialize min1
    int min1 = 0;

    //initialize min2
    int min2 = 0;
    int idx1 = -1;

    //iterate for all the rows
    for (int i = 0; i < n; i++)
    {
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        int idx2 = -1;

        //for all colums
        for (int j = 0; j < k; j++)
        {
            int cost = costs[i][j];
            if (j == idx1)
                cost += min2;
            else
                cost += min1;

            if (cost < m1)
            {
                m2 = m1;
                m1 = cost;
                idx2 = j;
            }
            else if (cost < m2)
            {
                m2 = cost;
            }
        }

        min1 = m1;
        min2 = m2;
        idx1 = idx2;
    }

    return min1;
}

int main()
{
    vector<vector<int>> costs = {{1, 3, 4, 2},
                                 {4, 5, 6, 5},
                                 {2, 3, 4, 7}};

    cout << minCostHouseColor(costs);

    return 0;
}