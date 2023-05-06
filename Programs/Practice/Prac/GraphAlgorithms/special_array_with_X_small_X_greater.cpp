#include <bits/stdc++.h>
using namespace std;

int specialArray(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), greater<int>());
    int res = 0;
    for (int i = 1; i <= nums.size(); i++)
    {
        if (nums[i - 1] >= i)
            res = i;
        else if (nums[i - 1] == res)
            return -1;
    }
    return res;
}

int main()
{
    vector<int> nums = {3, 5};
    cout << specialArray(nums);
    return 0;
}