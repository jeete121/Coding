#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    int low = 0, high = nums.size() - 1;
    if (nums[high] > nums[0])
        return nums[0];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1])
            return nums[mid + 1];
        else if (nums[mid - 1] > nums[mid])
            return nums[mid];
        if (nums[mid] > nums[0])
            low = mid + 1;
        if (nums[mid] < nums[0])
            high = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findMin(nums);
    return 0;
}
