#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    if (nums.size() == 0)
        return -1;
    vector<int> left, right;
    left.resize(nums.size());
    right.resize(nums.size());
    left[0] = nums[0];
    int n = nums.size();
    right[n - 1] = nums[n - 1];

    //find the sum of element before position i
    for (int i = 1; i < n; i++)
        left[i] = left[i - 1] + nums[i];

    //find the sum of element after position i
    for (int i = n - 2; i >= 0; i--)
        right[i] = right[i + 1] + nums[i];

    for (int i = 0; i < n; i++)
    {
        if (left[i] == right[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << pivotIndex(nums);
    return 0;
}