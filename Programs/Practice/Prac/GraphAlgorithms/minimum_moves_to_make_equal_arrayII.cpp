#include <bits/stdc++.h>
using namespace std;

int minMoves2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int len = n / 2;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(nums[i] - nums[len]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    cout << minMoves2(nums);

    return 0;
}