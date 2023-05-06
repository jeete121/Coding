#include <bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{
    vector<int> res;
    int n = nums.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }
    int duplicate, missing;
    for (int i = 1; i <= n; i++)
    {
        if (mp[i] > 1)
        {
            duplicate = i;
        }
        if (mp[i] == 0)
        {
            missing = i;
        }
    }
    res.push_back(duplicate);
    res.push_back(missing);
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 2, 4};

    vector<int> res = findErrorNums(nums);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}