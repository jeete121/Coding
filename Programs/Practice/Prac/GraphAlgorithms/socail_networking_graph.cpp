#include <bits/stdc++.h>
using namespace std;

vector<long long> arr[100001];
long long vis[1000001];
long long dist[1000001];
void bfs(long long src)
{
    queue<long long> q;
    q.push(src);
    dist[src] = 0;
    vis[src] = 1;
    while (!q.empty())
    {
        long long curr = q.front();
        q.pop();
        for (long long child : arr[curr])
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
long long socialNetworkingGraph(vector<vector<long long>> &edges,
                                long long n, long long e,
                                long long x, long long d)

{
    for (long long i = 0; i < e; i++)
    {
        long long a = edges[i][0], b = edges[i][1];

        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (long long i = 0; i <= n; i++)
    {
        vis[i] = 0;
        dist[i] = 0;
    }
    bfs(x);
    long long cnt = 0;
    for (long long i = 0; i <= n; i++)
    {
        if (dist[i] == d)
            cnt++;
    }
    return cnt;
}
int main()
{
    long long n = 9, e = 10;
    vector<vector<long long>> edges = {{1, 2},
                                       {2, 3},
                                       {1, 7},
                                       {2, 4},
                                       {3, 4},
                                       {4, 7},
                                       {7, 8},
                                       {9, 7},
                                       {7, 6},
                                       {5, 6}};

    long long x = 4, d = 2;
    cout << socialNetworkingGraph(edges, n, e, x, d) << "\n";

    return 0;
}