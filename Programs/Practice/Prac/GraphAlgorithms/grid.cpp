#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int vis[1001][1001];
int dist[1001][1001];

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    if (vis[x][y] == 1 || grid[x][y] == '*')
        return false;
    return true;
}

void bfs(int srcx, int srcy)
{
    queue<pair<int, int>> q;
    vis[srcx][srcy] = 1;

    q.push({srcx, srcy});
    dist[srcx][srcy] = 0;
    while (!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (isValid(currx + dx[i], curry + dy[i]))
            {
                int newx = currx + dx[i];
                int newy = curry + dy[i];
                q.push({newx, newy});
                dist[newx][newy] = dist[currx][curry] + 1;
                vis[newx][newy] = 1;
            }
        }
    }
}
int main()
{

    n = 3;
    m = 3;

    vector<string> vec = {"O*O", "OOO", "*OO"};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            grid[i][j] = vec[i - 1][j - 1];
    }

    int srcx = 2, srcy = 2;

    bfs(srcx, srcy);

    int a = 1, b = 1;
    if (a == srcx && b == srcy)
        cout << 0 << "\n";
    else if (dist[a][b] == 0)
        cout << -1 << "\n";
    else
        cout << dist[a][b] << "\n";

    return 0;
}