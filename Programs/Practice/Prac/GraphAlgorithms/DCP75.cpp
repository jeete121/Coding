#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (ans < dp[i])
        {
            ans = dp[i];
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {0, 8, 4, 12, 2, 10, 6, 14,
                        1, 9, 5, 13, 3, 11, 7, 15};
    cout << longestIncreasingSubsequence(nums);
    return 0;
}