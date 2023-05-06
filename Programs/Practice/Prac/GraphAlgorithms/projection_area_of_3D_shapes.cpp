#include <bits/stdc++.h>
using namespace std;

int projectionArea(vector<vector<int>> &grid)
{
    // 1: Top view: how many grids have the cubes
    // 2: Front view: maximum number of cubes in a column
    // 3: Side view: maximum number of cubes in a row
    int top = 0, front = 0, side = 0, size = grid.size();
    vector<int> maxCubesInCol(size);
    for (int i = 0; i < size; ++i)
    {
        int maxCubesInRow = 0;
        for (int j = 0; j < size; ++j)
        {

            //cubes
            int cubes = grid[i][j];

            //update top value
            top = cubes > 0 ? top + 1 : top;

            //uodate number of cubes in the row
            maxCubesInRow = cubes > maxCubesInRow ? cubes : maxCubesInRow;

            //maximum number of cubes in the colums
            maxCubesInCol[j] = cubes > maxCubesInCol[j] ? cubes : maxCubesInCol[j];
        }

        //update side
        side += maxCubesInRow;
    }

    front = accumulate(maxCubesInCol.begin(), maxCubesInCol.end(), 0);
    return front + side + top;
}

int main()
{
    vector<vector<int>> grid = {{1, 2}, {3, 4}};

    cout << projectionArea(grid);

    return 0;
}