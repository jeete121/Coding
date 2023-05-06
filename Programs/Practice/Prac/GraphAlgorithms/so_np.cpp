#include <bits/stdc++.h>
using namespace std;

vector<int> arr[1000001];
int vis[1000001];
void dfs(int v)
{
    vis[v] = 1;
    for (int child : arr[v])
    {
        if (vis[child] == 0)
        {
            dfs(child);
        }
    }
}

int soNP(int n, int m, int k, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < m; i++)
    {
        int a = edges[i].first, b = edges[i].second;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i);
            cnt++;
        }
    }
    if (cnt > k)
        return -1;
    else
        return m - n + k;
}
int main()
{
    int n = 4, m = 3, k = 2;
    vector<pair<int, int>> edges = {{1, 2},
                                    {2, 3},
                                    {1, 3}};

    cout << soNP(n, m, k, edges) << "\n";

    return 0;
}