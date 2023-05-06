#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int tree[200010];
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
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
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}
int n;
void NumArray(vector<int> &nums)
{
    n = nums.size();
    for (int i = 0; i < n; i++)
        arr[i + 1] = nums[i];
    if (n > 0)
        build(1, 1, n);
}

int sumRange(int i, int j)
{
    int ans = query(1, 1, n, i + 1, j + 1);
    return ans;
}

int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray(nums);
    cout << sumRange(0, 2);

    return 0;
}