#include <bits/stdc++.h>
using namespace std;
int arr[1000000];
int tree[2000000];
int tree1[2000010];
void build1(int node, int start, int end)
{
    if (start == end)
    {
        if (arr[start] == 0)
            tree1[node] = 1;
        else
            tree1[node] = 0;
    }
    else
    {
        int mid = (start + end) / 2;
        build1(2 * node, start, mid);
        build1(2 * node + 1, mid + 1, end);
        tree1[node] = tree1[2 * node] + tree1[2 * node + 1];
    }
}
int query1(int node, int start, int end, int l, int r)
{
    if (r < start || l > end)
        return 0;
    if (l <= start && r >= end)
        return tree1[node];
    else
    {
        int mid = (start + end) / 2;
        int p1 = query1(2 * node, start, mid, l, r);
        int p2 = query1(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }
}
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }
}
int query(int node, int start, int end, int l, int r)
{
    if (r < start || l > end)
        return 0;
    if (l <= start && r >= end)
        return tree[node];
    else
    {
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return p1 ^ p2;
    }
}
int main()
{
    int n = 5;
    int a[] = {1, 0, 0, 0, 1};
    for (int i = 1; i <= n; i++)
        arr[i] = a[i - 1];
    build(1, 1, n);
    build1(1, 1, n);

    int l = 2, r = 4;

    int ans = query(1, 1, n, l, r);
    int ans2 = query1(1, 1, n, l, r);
    cout << ans << " " << ans2 << "\n";

    return 0;
}