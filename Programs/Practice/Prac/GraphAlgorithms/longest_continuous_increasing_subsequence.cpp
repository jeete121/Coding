#include <bits/stdc++.h>
using namespace std;

int findLengthOfLCIS(vector<int> &nums)
{
    int prevCount = INT_MIN;
    int currentCount = 0;
    if (nums.size() == 0)
        return 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] - nums[i] > 0)
            currentCount++;
        else
        {
            prevCount = max(prevCount, currentCount);
            currentCount = 0;
        }
    }
    return max(prevCount, currentCount) + 1;
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};

    cout << findLengthOfLCIS(nums);

    return 0;
}