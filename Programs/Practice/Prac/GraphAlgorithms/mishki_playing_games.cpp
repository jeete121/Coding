#include <bits/stdc++.h>
using namespace std;

int countBits(int n)
{
    int res = 0;
    while (n)
    {
        res++;
        n = n / 2;
    }
    return res;
}
int arr[1000001];
int tree[2000010];
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = countBits(arr[start]);
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
int query(int node, int start, int end, int l, int r)
{
    if (start > r || l > end)
        return 0;
    if (start >= l && end <= r)
        return tree[node];
    else
    {
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }
}

void miskiPlayingGames(int n, int q, vector<vector<int>> &queries)
{

    for (int i = 0; i < q; i++)
    {
        int l = queries[i][0], r = queries[i][1];

        int ans = query(1, 1, n, l, r);
        if (ans & 1)
            cout << "Mishki\n";
        else
            cout << "Hacker\n";
    }
}
int main()
{

    int n = 3, q = 2;
    int a[] = {4, 2, 3};
    for (int i = 1; i <= n; i++)
        arr[i] = a[i - 1];
    build(1, 1, n);
    vector<vector<int>> queries = {{1, 2}, {2, 3}};

    miskiPlayingGames(n, q, queries);

    return 0;
}