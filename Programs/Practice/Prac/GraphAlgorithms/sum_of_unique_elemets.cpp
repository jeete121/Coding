#include <bits/stdc++.h>
using namespace std;

int sumOfUnique(vector<int> &nums)
{

    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    int sum = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == 1)
        {
            sum += it->first;
        }
    }
    return sum;
}
int main()
{
    vector<int> nums = {1, 2, 3, 2};

    cout << sumOfUnique(nums);

    return 0;
}