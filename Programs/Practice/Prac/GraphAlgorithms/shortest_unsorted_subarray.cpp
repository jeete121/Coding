#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<int> minMax(vector<int> &nums, int l, int r)
{
    int min1 = INT_MAX, max1 = INT_MIN;
    for (int i = l; i <= r; i++)
    {
        if (nums[i] > max1)
            max1 = nums[i];
        if (nums[i] < min1)
            min1 = nums[i];
    }
    return {min1, max1};
}
void fun(vector<int> &nums, int l, int r)
{
    vector<int> f = minMax(nums, l, r);
    if (f[0] == nums[l] && f[1] == nums[r])
    {
        l = l + 1;
        r = r - 1;
        if (l < r)
            fun(nums, l, r);
        else
        {
            ans = 0;
            return;
        }
    }
    else if (f[0] == nums[l])
    {
        l = l + 1;
        if (l < r)
            fun(nums, l, r);
        else
        {
            ans = 0;
            return;
        }
    }
    else if (f[1] == nums[r])
    {
        r = r - 1;
        if (l < r)
            fun(nums, l, r);
        else
        {
            ans = 0;
            return;
        }
    }
    else
    {
        ans = r - l + 1;
        return;
    }
}
int findUnsortedSubarray(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    fun(nums, l, r);
    return ans;
}

int main()
{
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout << findUnsortedSubarray(nums);
    return 0;
}