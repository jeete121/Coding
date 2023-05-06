#include <bits/stdc++.h>
using namespace std;

int maximumGap(vector<int> &nums)
{
    //sort the array
    sort(nums.begin(), nums.end());
    if (nums.size() < 2)
        return 0;
    int ans = INT_MIN;
    for (int i = 1; i < nums.size(); i++)
    {
        ans = max(ans, nums[i] - nums[i - 1]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 6, 9, 1};
    cout << maximumGap(nums);
    return 0;
}