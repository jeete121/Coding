#include <bits/stdc++.h>
using namespace std;
int grid[100][100];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m;
int cnt;
int vis[100][100];
bool isValid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (vis[x][y] == 1 || grid[x][y] == 0)
        return false;
    return true;
}
void dfs(int x, int y)
{
    vis[x][y] = 1;
    cnt++;
    for (int i = 0; i < 8; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
    }
}
int main()
{
    n = 3, m = 3;
    grid[0][0] = 1, grid[0][1] = 1, grid[0][2] = 0;
    grid[1][0] = 1, grid[1][1] = 0, grid[1][2] = 0;
    grid[2][0] = 0, grid[2][1] = 0, grid[2][2] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = 0;
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (vis[i][j] == 0 && grid[i][j] == 1)
            {
                cnt = 0;
                dfs(i, j);
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
