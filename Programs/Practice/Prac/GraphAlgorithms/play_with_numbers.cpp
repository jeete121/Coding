#include <bits/stdc++.h>
using namespace std;

long long tree[2000012];
long long arr[1000002];
void build(long long node, long long start, long long end)
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
    if (l <= start && r >= end)
        return tree[node];
    long long mid = (start + end) / 2;
    long long p1 = query(node * 2, start, mid, l, r);
    long long p2 = query(node * 2 + 1, mid + 1, end, l, r);
    return p1 + p2;
}

void playWithNumbers(long long n, long long q,
                     long long a[],
                     vector<vector<long long>> &queries)
{
    for (long long i = 1; i <= n; i++)
        arr[i] = a[i - 1];
    build(1, 1, n);

    for (long long i = 0; i < q; i++)
    {
        long long l = queries[i][0], r = queries[i][1];

        long long sum;
        sum = query(1, 1, n, l, r);

        cout << sum / (r - l + 1) << "\n";
    }
}
int main()
{

    long long n = 5, q = 3;
    long long a[] = {1, 2, 3, 4, 5};
    vector<vector<long long>> queries = {{1, 3}, {2, 4}, {2, 5}};

    playWithNumbers(n, q, a, queries);

    return 0;
}