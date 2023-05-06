#include <bits/stdc++.h>
using namespace std;

int dominantIndex(vector<int> &nums)
{
    int max1 = 0;
    int n = nums.size(), j;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > max1)
        {
            max1 = nums[i];
            j = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != j && nums[j] < 2 * nums[i])
            return -1;
    }
    return j;
}

int main()
{
    vector<int> nums = {3, 6, 1, 0};
    cout << dominantIndex(nums);
    return 0;
}