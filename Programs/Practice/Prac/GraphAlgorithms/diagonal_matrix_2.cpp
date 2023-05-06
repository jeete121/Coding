#include <bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>> &nums)
{

    int n = nums.size();
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i].size() > m)
            m = nums[i].size();
    }
    vector<vector<int>> ans(n + m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            ans[i + j].push_back(nums[i][j]);
        }
    }
    vector<int> res;
    for (int i = 0; i < ans.size(); i++)
    {
        reverse(ans[i].begin(), ans[i].end());
        for (int j = 0; j < ans[i].size(); j++)
        {
            res.push_back(ans[i][j]);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    vector<int> res = findDiagonalOrder(matrix);

    cout << "[";

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}