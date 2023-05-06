#include <bits/stdc++.h>
using namespace std;

map<int, vector<pair<int, int>>> ways;
int rows, cols;
vector<bool> vis;

bool check(int x, int y, int nx, int ny, int value)
{
    vector<pair<int,int>> w=ways[value];
    for(int i=0;i<w.size();i++)
      {
          if(nx+w[i].first==x&&ny+w[i].second==y)
            {
                return true;
            }
      }
 
    return false;
}
bool dfs(int x, int y, vector<vector<int>> &grid)
{
    if (x == rows - 1 && y == cols - 1)
        return true;
    int value = grid[x][y];
    vector<pair<int,int>> w=ways[value];

    for(int i=0;i<w.size();i++)
    { 
  
        int nx = w[i].first + x, ny = w[i].second + y;
        if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && !vis[nx * cols + ny] && check(x, y, nx, ny, grid[nx][ny]))
        {
            vis[nx * cols + ny] = true;
            if (dfs(nx, ny, grid))
                return true;
        }
    }
    return false;
}

bool hasValidPath(vector<vector<int>> &grid)
{
    rows = grid.size();
    if (rows == 0)
        return true;
    cols = grid[0].size();
    ways[1] = {{0, -1}, {0, 1}};
    ways[2] = {{-1, 0}, {1, 0}};
    ways[3] = {{0, -1}, {1, 0}};
    ways[4] = {{1, 0}, {0, 1}};
    ways[5] = {{0, -1}, {-1, 0}};
    ways[6] = {{-1, 0}, {0, 1}};
    vis.resize(rows * cols + 1);
    return dfs(0, 0, grid);
}

int main()
{
    vector<vector<int>> grid = {{2, 4, 3}, {6, 5, 2}};

    if (hasValidPath(grid))
        cout << "true";
    else
        cout << "false";

    return 0;
}