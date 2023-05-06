#include <bits/stdc++.h>
using namespace std;
long long arr[1000010];
long long tree[2000010];

bool special(long long n)
{
    if ((n & (n >> 1)) != 0)
        return true;
    else
        return false;
}
void build(long long node, long long start, long long end)
{
    if (start == end)
    {

        if (special(arr[start]))
            tree[node] = 1;
        else
            tree[node] = 0;
    }
    else
    {
        long long mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
long long query(long long node, long long start, long long end, long long l, long long r)
{
    if (r < start || l > end)
        return 0;
    if (l <= start && r >= end)
        return tree[node];
    else
    {
        long long mid = (start + end) / 2;
        long long p1 = query(2 * node, start, mid, l, r);
        long long p2 = query(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }
}

void specialBitNumbers(int n, int q, vector<vector<int>> &queries)
{

    for (int i = 0; i < q; i++)
    {
        long long l = queries[i][0], r = queries[i][1];
        long long ans = query(1, 1, n, l, r);
        cout << ans << "\n";
    }
}
int main()
{
    long long n = 5, q = 3;
    int a[] = {3, 5, 1, 12, 7};

    for (long long i = 1; i <= n; i++)
        arr[i] = a[i - 1];
    vector<vector<int>> queries = {{1, 3}, {2, 3}, {1, 5}};
    build(1, 1, n);
    specialBitNumbers(n, q, queries);
    return 0;
}