#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int tree[400004];
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int query(int node, int start, int end, int l, int r)
{
    if (r < start || l > end)
        return 0;
    if (l <= start && r >= end)
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}
void update(int node, int start, int end, int index, int val)
{
    if (start == end)
    {
        tree[node] = tree[node] - arr[start] + val;
        arr[index] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (index <= mid && start <= index)
        update(2 * node, start, mid, index, val);
    else
        update(2 * node + 1, mid + 1, end, index, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void helpAshu(int n, int q, vector<vector<int>> &queries)
{

    for (int i = 0; i < q; i++)
    {
        int x = queries[i][0], y = queries[i][1], z = queries[i][2];

        if (x == 0)
        {
            if (z & 1)
                update(1, 1, n, y, 0);
            else
                update(1, 1, n, y, 1);
        }
        else if (x == 2)
        {
            cout << z - y + (y != z ? 1 : 0) -
                        query(1, 1, n, y, z)
                 << "\n";
        }
        else
            cout << query(1, 1, n, y, z) << "\n";
    }
}
int main()
{
    int n = 6;
    int a[n] = {1, 2, 3, 4, 5, 6};
    int q = 4;
    vector<vector<int>> queries = {{1, 2, 5},
                                   {2, 1, 4},
                                   {0, 5, 4},
                                   {1, 1, 6}};
    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] & 1)
            arr[i] = 0;
        else
            arr[i] = 1;
    }
    build(1, 1, n);

    helpAshu(n, q, queries);

    return 0;
}