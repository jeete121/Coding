#include <bits/stdc++.h>
using namespace std;
vector<int> arr[1000001];
int vis[1000001];
int dist[1000001];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    vis[node] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int child : arr[curr])
        {
            if (vis[child] == 0)
            {
                dist[child] = dist[curr] + 6;
                vis[child] = 1;
                q.push(child);
            }
        }
    }
}
int main()
{

    int n = 4, m = 2;
    for (int i = 1; i <= n; i++)
    {
        arr[i].clear();
        vis[i] = 0;
    }
    arr[1].push_back(2);
    arr[2].push_back(1);

    arr[1].push_back(3);
    arr[3].push_back(1);
    int s = 1;
    bfs(s);
    for (int i = 1; i <= n; i++)
    {
        if (i == s)
            continue;
        if (vis[i] == 0)
            cout << -1 << " ";
        else
            cout << dist[i] << " ";
    }
    cout << "\n";
    return 0;
}
