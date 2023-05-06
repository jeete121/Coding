#include <bits/stdc++.h>
using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    vector<int> res;
    int indegree[n];
    for (int i = 0; i < n; i++)
        indegree[i] = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        indegree[y]++;
    }
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            res.push_back(i);
    return res;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, 
                            {3, 4}, {4, 2}};
    vector<int> ans = findSmallestSetOfVertices(n, edges);
    cout << "[";
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << ",";
    }
    cout << ans[ans.size() - 1] << "]";
    return 0;
}