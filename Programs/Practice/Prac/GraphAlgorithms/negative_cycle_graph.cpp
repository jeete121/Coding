#include <bits/stdc++.h>
using namespace std;

//structute of the edges
struct Edge
{
    int a, b, cost;
};

int n, m;

//vector array to hold all
//the edges
vector<Edge> edges;
const int INF = INT_MAX;

void negativeCycle()
{
    //array to hold the distance of
    //all nodes
    vector<int> dist(n + 1);

    //array to hold the parent of
    //all nodes
    vector<int> parent(n + 1, -1);
    int x;

    //iterate for all nodes
    for (int i = 0; i < n; ++i)
    {
        x = -1;

        //iterate for all the edges
        for (Edge e : edges)
        {

            //update the distance and
            //parent
            if (dist[e.a] + e.cost < dist[e.b])
            {
                dist[e.b] = dist[e.a] + e.cost;
                parent[e.b] = e.a;
                x = e.b;
            }
        }
    }
    //if no cycle
    if (x == -1)
    {
        cout << "No negative cycle found.";
    }

    //else cycle is present
    else
    {
        for (int i = 0; i < n; ++i)
            x = parent[x];

        vector<int> cycle;
        for (int v = x;; v = parent[v])
        {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "Negative cycle: ";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}

int main()
{
    n = 4, m = 4;
    edges.push_back({1, 2, 3});
    edges.push_back({2, 3, -5});
    edges.push_back({3, 1, -2});
    edges.push_back({3, 4, 5});
    negativeCycle();
    return 0;
}