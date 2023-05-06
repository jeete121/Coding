#include <bits/stdc++.h>
using namespace std;


//function to find the peak element in the
//array
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1])
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << findPeakElement(nums);
    return 0;
}