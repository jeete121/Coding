#include <bits/stdc++.h>
using namespace std;

int surfaceArea(vector<vector<int>> &grid)
{
    int cube = 0, sf = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {

            //if grid at current position is zero
            //then continue
            if (grid[i][j] == 0)
            {
                continue;
            }

            //update cube value
            cube += grid[i][j];

            //update surface area
            //-1 for top
            sf += grid[i][j] - 1;

            //now update surface area
            if (j + 1 < grid[0].size())
            {
                sf += min(grid[i][j], grid[i][j + 1]);
            }

            //updare surface area
            if (i + 1 < grid.size())
            {
                sf += min(grid[i][j], grid[i + 1][j]);
            }
        }
    }
    return cube * 6 - sf * 2;
}
int main()
{
    vector<vector<int>> grid = {{1, 2}, {3, 4}};

    cout << surfaceArea(grid);

    return 0;
}