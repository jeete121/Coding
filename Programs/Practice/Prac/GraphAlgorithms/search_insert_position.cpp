#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int low = 0, high = nums.size();

    //if target value is greater then last
    //element value
    if (target > nums[nums.size() - 1])
        return nums.size();

    //if target value is less than first element value
    if (target < nums[0])
        return 0;

    //search for position
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << searchInsert(nums, target);
    return 0;
}