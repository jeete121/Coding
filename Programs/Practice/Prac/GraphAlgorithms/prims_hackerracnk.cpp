#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
struct Edge
{
    int to, cost = INF;
};
int main()
{

    int n = 5, m = 6, s = 1;
    vector<list<Edge>> arr(n, list<Edge>());
    set<pair<int, int>> left;
    set<int> add;
    vector<Edge> mst;
    vector<int> dist(n + 1, INT_MAX);
    arr[0].push_back(Edge{1, 3});
    arr[1].push_back(Edge{0, 3});

    arr[0].push_back(Edge{2, 4});
    arr[2].push_back(Edge{0, 4});

    arr[3].push_back(Edge{1, 6});
    arr[1].push_back(Edge{3, 6});

    arr[4].push_back(Edge{1, 2});
    arr[1].push_back(Edge{4, 2});

    arr[1].push_back(Edge{2, 5});
    arr[2].push_back(Edge{1, 5});

    arr[2].push_back(Edge{4, 7});
    arr[4].push_back(Edge{2, 7});

    s--;
    dist[s] = 0;
    for (int i = 0; i < n; i++)
    {
        left.insert({dist[i], i});
    }
    int ans = 0;
    while (!left.empty())
    {
        int curr = left.begin()->second;
        ans += dist[curr];
        add.insert(curr);
        left.erase(left.begin());
        for (auto &edge : arr[curr])
        {
            if (add.count(edge.to) == 1)
                continue;
            int curr_min = dist[edge.to];
            if (edge.cost < curr_min)
            {
                left.erase({curr_min, edge.to});
                dist[edge.to] = edge.cost;
                left.insert({dist[edge.to], edge.to});
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
