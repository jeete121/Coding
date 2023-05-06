#include <bits/stdc++.h>
using namespace std;
vector<long long int> arr[1000001];
long long int vis[1000001];
vector<long long int> res;
long long int INF = -10000000000;
long long int n;
void dfs(long long int node)
{
    vis[node] = 1;
    for (long long int child : arr[node])
    {
        if (vis[child] == 0)
            dfs(child);
    }
    res.push_back(node);
}
void toposort()
{
    for (long long int i = 1; i <= n; i++)
        vis[i] = 0;
    res.clear();
    for (long long int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i);
    }
    reverse(res.begin(), res.end());
}
int main()
{
    long long int m;
    cin >> n >> m;
    while (m--)
    {
        long long int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }
    toposort();
    //  for(long long int i=0;i<res.size();i++)
    //     cout<<res[i]<<" ";
    //     cout<<"\n";
    long long int dist[n + 1];
    for (long long int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[1] = 0;
    long long int parent[n + 1] = {-1};
    for (long long int i = 0; i < res.size(); i++)
    {
        long long int node = res[i];
        for (long long int child : arr[res[i]])
        {
            if (dist[res[i]] + 1 > dist[child])
            {
                dist[child] = dist[res[i]] + 1;
                parent[child] = res[i];
            }
        }
    }
    if (dist[n] < 0)
        cout << "IMPOSSIBLE\n";
    else
    {
        vector<long long int> path;
        for (long long int i = n; i != -1; i = parent[i])
            path.push_back(i);
        cout << dist[n] + 1 << "\n";
        reverse(path.begin(), path.end());
        for (long long int i = 1; i < path.size(); i++)
            cout << path[i] << " ";
    }
    return 0;
}