#include <bits/stdc++.h>
using namespace std;

int parent[100001];
int find(int a)
{
    if (parent[a] < 0)
        return a;
    int x = find(parent[a]);
    parent[a] = x;
    return x;
}
void union1(int a, int b)
{
    parent[a] = min(parent[a], parent[b]);
    parent[b] = a;
}

void owlFight(int n, int m,
              vector<vector<int>> &connections,
              int q, vector<vector<int>> &queries)
{
    int a, b, x, y;
    for (int i = 0; i < m; i++)
    {
        a = connections[i][0];
        b = connections[i][1];
        a = find(a);
        b = find(b);
        if (a != b)
            union1(a, b);
    }

    for (int i = 0; i < q; i++)
    {
        a = queries[i][0];
        b = queries[i][1];
        x = a;
        y = b;
        a = find(a);
        b = find(b);
        if (a == b)
            cout << "TIE\n";
        else
        {
            if (parent[a] < parent[b])
                cout << x << "\n";
            else
                cout << y << "\n";
        }
    }
}
int main()
{
    int n = 7, m = 3;

    vector<vector<int>> connections = {{1, 2}, {3, 4}, {1, 7}};
    int q = 4;
    vector<vector<int>> queries = {{1, 2}, {5, 6}, {3, 7}, {1, 5}};
    for (int i = 1; i <= n; i++)
        parent[i] = -i;

    owlFight(n, m, connections, q, queries);

    return 0;
}