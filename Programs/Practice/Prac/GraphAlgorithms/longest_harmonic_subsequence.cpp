#include <bits/stdc++.h>
using namespace std;

int findLHS(vector<int> &nums)
{
    int ans = 0;
    unordered_map<int, int> ump;

    //count frequency of each elements
    for (int i : nums)
    {
        ump[i]++;
    }

    //iterate for all elements
    for (int i = 0; i < nums.size(); i++)
    {
        int a = ump[nums[i] - 1];
        int b = ump[nums[i] + 1];
        if (a > 0 || b > 0)
            ans = max(ans, ump[nums[i]] + max(a, b));
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << findLHS(nums);
    return 0;
}