#include <bits/stdc++.h>
using namespace std;

bool fun(vector<int> &nums, int target, int low, int high)
{
    //base case
    if (low > high)
        return false;

    //calculate mid point
    int mid = (low + high) / 2;

    //if mid value is same as target then return true
    if (nums[mid] == target)
        return true;

    //call for left and right subparts
    return fun(nums, target, low, mid - 1) || fun(nums, target, mid + 1, high);
}
bool search(vector<int> &nums, int target)
{
    return fun(nums, target, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    if (search(nums, target))
        cout << "true";
    else
        cout << "false";
    return 0;
}