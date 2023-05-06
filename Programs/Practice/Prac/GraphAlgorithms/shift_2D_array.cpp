#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{
    int n = grid.size();
    int m = grid[0].size();
    int total = n * m;
    k = k % total;
    vector<int> v, v1;
    k = total - k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (k > 0)
            {
                v.push_back(grid[i][j]);
                k--;
            }
            else
                v1.push_back(grid[i][j]);
        }
    }
    int l = 0, l1 = 0;
    int len = v1.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (len > 0)
            {
                len--;
                grid[i][j] = v1[l++];
            }
            else
            {
                grid[i][j] = v[l1++];
            }
        }
    }
    return grid;
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 1;
    grid = shiftGrid(grid, k);
    cout << "[";
    for (int i = 0; i < grid.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < grid[i].size(); j++)
        {
            cout << grid[i][j];
            if (j != grid[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != grid.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}