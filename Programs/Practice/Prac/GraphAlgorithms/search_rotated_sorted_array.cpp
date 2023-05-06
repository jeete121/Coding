#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    //iterate till low is less than high
    while (low <= high)
    {

        //calculate mid point
        int mid = low + (high - low) / 2;

        //if target value is same as mid
        //value then return it
        if (nums[mid] == target)
            return mid;

        //if mid value is less than low value
        else if (nums[mid] < nums[low])
        {
            //if target is greater than mid and target is less than
            //high than update low
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;

            //else update high
            else
                high = mid - 1;
        }

        //if mid value is greater than high
        else if (nums[mid] > nums[high])
        {

            //if target is less than mid and target is greater than
            //low then update high
            if (target < nums[mid] && target >= nums[low])
                high = mid - 1;

            //else update low
            else
                low = mid + 1;
        }
        else
        {
            //update high
            if (target < nums[mid])
                high = mid - 1;

            //else update low
            else
                low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << search(nums, target);
    return 0;
}