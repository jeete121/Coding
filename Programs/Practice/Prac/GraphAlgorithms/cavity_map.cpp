#include <bits/stdc++.h>
using namespace std;

vector<string> cavityMap(vector<string> grid)
{

    int n = grid.size();
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (grid[i][j] > grid[i][j - 1] &&
                grid[i][j] > grid[i][j + 1] &&
                grid[i][j] > grid[i - 1][j] &&
                grid[i][j] > grid[i + 1][j])
            {
                grid[i][j] = 'X';
            }
        }
    }
    vector<string> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back(grid[i]);
    }
    return res;
}
int main()
{
    int n = 4;

    vector<string> grid = {"1112", "1912", "1892", "1234"};
    vector<string> res = cavityMap(grid);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "\n";
    }
    return 0;
}
