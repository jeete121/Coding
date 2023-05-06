#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
long long int rangeSum(vector<int> &nums, int n, int left, int right)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        long long int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            v.push_back(sum);
        }
    }
    sort(v.begin(), v.end());
    long long int ans[v.size() + 1];
    memset(ans, 0, sizeof(ans));
    ans[1] = v[0];
    for (int i = 1; i < v.size(); i++)
        ans[i + 1] = (v[i] + ans[i]) % MOD;
    return ans[right] - ans[left - 1];
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int n = 4, left = 1, right = 5;
    cout << rangeSum(nums, n, left, right);
    return 0;
}