#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 50001;
int findShortestSubArray(vector<int> &nums)
{
    map<int, int> mp;
    int max1 = -1;
    vector<int> firstIndex(MAX_SIZE, -1), lastIndex(MAX_SIZE, -1);

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
        max1 = max(max1, mp[nums[i]]);
        if (firstIndex[nums[i]] == -1)
        {
            firstIndex[nums[i]] = i;
        }
        lastIndex[nums[i]] = i;
    }

    vector<int> maxFreq;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp[nums[i]] == max1)
        {
            maxFreq.push_back(nums[i]);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < maxFreq.size(); i++)
    {
        int diff = lastIndex[maxFreq[i]] - firstIndex[maxFreq[i]] + 1;
        ans = min(ans, diff);
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 2, 3, 1, 4, 2};

    cout << findShortestSubArray(nums);

    return 0;
}