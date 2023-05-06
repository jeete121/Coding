#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid,
         int i, int j, int n, int m)
{

    //check if cell is valid or not
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
        return;
    grid[i][j] = 0;

    //call for all four directions
    dfs(grid, i + 1, j, n, m);
    dfs(grid, i - 1, j, n, m);
    dfs(grid, i, j + 1, n, m);
    dfs(grid, i, j - 1, n, m);
}
int numIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (n == 0)
        return 0;
    int num_islands = 0;
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(grid, i, j, n, m);
                num_islands += 1;
            }
        }
    }
    return num_islands;
}

int main()
{
    vector<vector<int>> grid = {{1, 0, 0, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0},
                                {1, 1, 0, 0, 1},
                                {1, 1, 0, 0, 1}};
    cout << numIslands(grid);
    return 0;
}