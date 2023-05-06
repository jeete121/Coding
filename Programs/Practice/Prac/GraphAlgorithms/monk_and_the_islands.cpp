#include <bits/stdc++.h>
using namespace std;

vector<int> arr[100001];
int vis[100001];
int dist[100001];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    vis[src] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int child : arr[curr])
        {
            if (vis[child] == 0)
            {
                vis[child] = 1;
                dist[child] = dist[curr] + 1;
                q.push(child);
            }
        }
    }
}

int theIslands(int n, int m, vector<vector<int>> &edges)
{
    for (int i = 1; i <= n; i++)
    {
        arr[i].clear();
        vis[i] = 0;
        dist[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a = edges[i][0], b = edges[i][1];
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    bfs(1);
    return dist[n];
}
int main()
{
    int n = 3, m = 2;

    vector<vector<int>> edges = {{1, 2}, {2, 3}};

    cout << theIslands(n, m, edges) << "\n";

    return 0;
}