#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> ump;
    for (int i = 0; i < nums.size(); i++)
    {
        if (ump.count(nums[i]) == 1)
        {
            if ((i - ump[nums[i]]) <= k)
                return true;
        }
        ump[nums[i]] = i;
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    if (containsNearbyDuplicate(nums, k))
        cout << "true";
    else
        cout << "false";
    return 0;
}