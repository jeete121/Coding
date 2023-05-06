#include <bits/stdc++.h>
using namespace std;
vector<int> arr[1001];
int vis[1001];
int dist[1001];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    dist[src] = 0;
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
int main()
{
    int n = 6;

    vector<vector<int>> edges = {{1, 2},
                                 {1, 3},
                                 {1, 4},
                                 {2, 5},
                                 {2, 6}};
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0], b = edges[i][1];

        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int q = 4;
    vector<int> queries = {5, 6, 3, 4};
    bfs(1);
    int ans, min1 = INT_MAX;
    for (int i = 0; i < q; i++)
    {
        int x = queries[i];

        if (dist[x] < min1)
        {
            ans = x;
            min1 = dist[x];
        }
    }
    cout << ans << "\n";

    return 0;
}