#include <bits/stdc++.h>
using namespace std;

bool flag = false;

void dfs(int node, int end, vector<bool> &vis, vector<vector<int>> &adj)
{

    //if current node is the end node then
    //we set flag as true as we found a path from start to end
    //and return from the function
    if (node == end)
    {
        flag = true;
        return;
    }

    //mark current node as visited so that we cannot
    //traverse the same node again and again.
    vis[node] = true;

    //iterate through all th adjacent nodes of current node
    for (int it : adj[node])
    {
        //if not visited then call for dfs
        //recursively
        if (vis[it] == false)
            dfs(it, end, vis, adj);
    }
}

bool validPath(int n, vector<vector<int>> &edges, int start, int end)
{

    vector<vector<int>> adj(n);

    //create a visisted array
    vector<bool> vis(n, false);

    //create a graph from the given edges
    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //call for dfs
    dfs(start, end, vis, adj);

    return flag;
}

int main()
{
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int start = 0, end = 2;

    if (validPath(n, edges, start, end))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}

