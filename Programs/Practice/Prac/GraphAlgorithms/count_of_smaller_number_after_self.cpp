#include <bits/stdc++.h>
using namespace std;

int tree[100001], M = 1;
void add(int v)
{
    while (v)
    {
        tree[v]++;
        v >>= 1;
    }
}
int get(int p, int k, int res = 0)
{
    while (p <= k && p != 0 && k != 0)
    {
        if (p % 2 == 1)
            res += tree[p++];
        if (k % 2 == 0)
            res += tree[k--];
        p >>= 1;
        k >>= 1;
    }
    return res;
}
vector<int> countSmaller(vector<int> &nums)
{
    set<int> s;
    map<int, int> m;
    int nr = 0;
    for (auto i : nums)
        s.insert(i);
    for (auto i : s)
        m[i] = nr++;
    while (M < nr)
        M <<= 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        add(m[nums[i]] + M);
        nums[i] = get(M, m[nums[i]] - 1 + M);
    }
    return nums;
}
int main()
{
    vector<int> nums = {5, 2, 6, 1};

    vector<int> res = countSmaller(nums);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}