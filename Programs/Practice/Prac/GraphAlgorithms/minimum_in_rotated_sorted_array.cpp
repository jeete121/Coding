#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1, mid = 0;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (nums[mid] > nums[high])
            low = mid + 1;
        else if (nums[mid] < nums[high])
            high = mid;
        else
            high--;
    }
    return nums[low];
}

int main()
{
    vector<int> arr = {2, 2, 2, 0, 1};
    cout << findMin(arr);
    return 0;
}