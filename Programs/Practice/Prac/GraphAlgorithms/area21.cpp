#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int tree[200010];
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
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
int query(int node, int start, int end, int l, int r)
{
    if (r < start || l > end)
        return 0;
    if (l <= start && r >= end)
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(node * 2, start, mid, l, r);
    int p2 = query(node * 2 + 1, mid + 1, end, l, r);
    return p1 + p2;
}
int main()
{
    bool prime[1000001];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= 1000001; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 1000001; j += i)
                prime[j] = false;
        }
    }
    int n = 4, q = 1;

    int a[n] = {2, 3, 5, 7};

    for (int i = 0; i < n; i++)
    {
        if (prime[a[i]])
            arr[i + 1] = 1;
        else
            arr[i + 1] = 0;
    }

    build(1, 1, n);

    int l = 1, r = 4;

    int ans = query(1, 1, n, l, r);
    cout << ans << "\n";
    return 0;
}