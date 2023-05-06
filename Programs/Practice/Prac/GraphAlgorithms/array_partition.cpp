#include <bits/stdc++.h>
using namespace std;

int arrayPairSum(vector<int> &nums)
{
    //sort the array
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0)
            res += nums[i];
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 4, 3, 2};
    cout << arrayPairSum(nums);
    return 0;
}