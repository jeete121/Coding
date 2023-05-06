#include <bits/stdc++.h>
using namespace std;

int dp[20010][201];
bool canPart(vector<int> &nums, int n, int sum)
{
    if (n < 0 || sum < 0)
        return false;
    if (sum == 0)
        return true;
    if (dp[sum][n] != -1)
        return dp[sum][n];
    dp[sum][n] = canPart(nums, n - 1, sum - nums[n]) ||
                 canPart(nums, n - 1, sum);
    return dp[sum][n];
}
bool canPartition(vector<int> &nums)
{

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    memset(dp, -1, sizeof(dp));
    if (sum & 1)
        return false;
    return canPart(nums, nums.size() - 1, sum / 2);
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};

    if (canPartition(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}