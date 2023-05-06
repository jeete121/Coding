#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> arr[1000001];

int main()
{

    int n = 4, m = 4;
    vector<int> dist(n + 1, INT_MAX);
    for (int i = 1; i <= n; i++)
    {
        arr[i].clear();
    }
    arr[1].push_back({2, 24});
    arr[2].push_back({1, 24});

    arr[1].push_back({4, 20});
    arr[4].push_back({1, 20});

    arr[3].push_back({1, 3});
    arr[1].push_back({3, 3});

    arr[4].push_back({3, 12});
    arr[3].push_back({4, 12});
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int s = 1;
    q.push({0, s});
    dist[s] = 0;
    while (!q.empty())
    {
        int curr = q.top().second;
        int curr_d = q.top().first;
        q.pop();
        if (curr_d != dist[curr])
            continue;
        if (curr_d == INT_MAX)
            break;
        for (pair<int, int> edge : arr[curr])
        {
            if (dist[edge.first] > curr_d + edge.second)
            {
                dist[edge.first] = curr_d + edge.second;
                q.push({dist[edge.first], edge.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == s)
            continue;
        if (dist[i] == INT_MAX)
            cout << -1 << " ";
        else
            cout << dist[i] << " ";
    }
    cout << "\n";
}