#include <bits/stdc++.h>
using namespace std;

int minDifference(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n <= 3)
        return 0;
    int a = nums[n - 4] - nums[0];
    int b = nums[n - 1] - nums[3];
    int c = nums[n - 2] - nums[2];
    int d = nums[n - 3] - nums[1];
    return min(a, min(b, min(c, d)));
}

int main()
{
    vector<int> nums = {1, 5, 0, 10, 14};
    cout << minDifference(nums);
    return 0;
}