#include <bits/stdc++.h>
using namespace std;

int maxCount(int m, int n, vector<vector<int>> &ops)
{
    if (ops.empty())
    {
        return m * n;
    }
    int min_x = m;
    int min_y = n;
    for (int i = 0; i < ops.size(); i++)
    {
        min_x = min(min_x, ops[i][0]);
        min_y = min(min_y, ops[i][1]);
    }
    return min_x * min_y;
}

int main()
{
    int m = 3, n = 3;
    vector<vector<int>> ops = {{2, 2}, {3, 3}};

    cout << maxCount(m, n, ops);

    return 0;
}