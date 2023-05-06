#include <bits/stdc++.h>
using namespace std;
char arr[10001][10001];
int vis[10001][10001];
int n;
int dist[10001][10001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n)
        return false;
    if (vis[x][y] == 1 || arr[x][y] == 'T')
        return false;
    return true;
}
void bfs(int srcx, int srcy)
{
    queue<pair<int, int>> q;
    q.push({srcx, srcy});
    vis[srcx][srcy] = 1;
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
                dist[newx][newy] = dist[currx][curry] + 1;
                vis[newx][newy] = 1;
                q.push({newx, newy});
            }
        }
    }
}

int jungleRun(int n, vector<vector<char>> &board)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            arr[i][j] = board[i - 1][j - 1];
    }
    int x, y, destx, desty;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == 'S')
            {
                x = i;
                y = j;
            }
            else if (arr[i][j] == 'E')
            {
                destx = i;
                desty = j;
            }
        }
    }
    bfs(x, y);
    return dist[destx][desty];
}
int main()
{
    n = 5;

    vector<vector<char>> board = {{'S', 'P', 'P', 'P', 'P'},
                                  {'T', 'P', 'T', 'P', 'P'},
                                  {'T', 'P', 'P', 'P', 'P'},
                                  {'P', 'T', 'E', 'T', 'T'},
                                  {'P', 'T', 'P', 'T', 'T'}};

    cout << jungleRun(n, board) << "\n";

    return 0;
}