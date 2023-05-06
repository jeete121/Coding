#include <bits/stdc++.h>
using namespace std;
long long arr[1000001];
long long tree[2000010];
void build(long long node,
           long long start, long long end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        long long mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
long long query(long long node, long long start,
                long long end, long long l, long long r)
{
    if (r < start || l > end)
        return 0;
    if (start >= l && end <= r)
        return tree[node];
    else
    {
        long long mid = (start + end) / 2;
        long long p1 = query(2 * node, start, mid, l, r);
        long long p2 = query(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }
}
void update(long long node, long long start,
            long long end, long long index, long long val)
{
    if (start == end)
    {
        arr[start] == val;
        tree[node] = val;
    }
    else
    {
        long long mid = (start + end) / 2;
        if (start <= index && index <= mid)
            update(2 * node, start, mid, index, val);
        else
            update(2 * node + 1, mid + 1, end, index, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
int main()
{
    long long n = 5, q = 5;

    long long a[n] = {2, 3, 4, 8, 9};
    for (long long i = 1; i <= n; i++)
        arr[i] = a[i - 1];
    build(1, 1, n);
    vector<pair<int, pair<int, int>>> queries = {{1, {0, 3}},
                                                 {2, {0, 1}},
                                                 {2, {0, 4}},
                                                 {1, {2, 5}},
                                                 {2, {0, 3}}};
    for (int i = 0; i < q; i++)
    {
        long long x = queries[i].first;
        long long l = queries[i].second.first;
        long long r = queries[i].second.second;

        if (x == 1)
        {
            update(1, 1, n, l + 1, r);
        }
        else
        {
            long long ans = query(1, 1, n, l + 1, r + 1);
            cout << ans << "\n";
        }
    }
    return 0;
}