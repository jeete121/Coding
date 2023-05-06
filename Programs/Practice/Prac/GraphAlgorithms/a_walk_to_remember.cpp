#include <bits/stdc++.h>
using namespace std;
vector<int> arr[100001], tr[100001];
int vis[100001];
vector<int> order, SCC;
void dfs(int node)
{
    vis[node] = 1;
    for (int child : arr[node])
    {
        if (vis[child] == 0)
            dfs(child);
    }
    order.push_back(node);
}
void dfs1(int node)
{
    vis[node] = 1;
    for (int child : tr[node])
    {
        if (vis[child] == 0)
            dfs1(child);
    }
    SCC.push_back(node);
}

void walkToRemember(int n, int m, vector<vector<int>> &edges)
{
    for (int i = 0; i < m; i++)
    {
        int a = edges[i][0], b = edges[i][1];

        arr[a].push_back(b);
        tr[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i);
    }
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    int res[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (vis[order[n - i]] == 0)
        {
            SCC.clear();
            dfs1(order[n - i]);
            if (SCC.size() > 1)
            {
                for (int node : SCC)
                    res[node] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
}
int main()
{
    int n = 5, m = 5;
    vector<vector<int>> edges = {{1, 2},
                                 {2, 3},
                                 {3, 4},
                                 {4, 5},
                                 {4, 2}};

    walkToRemember(n, m, edges);

    return 0;
}