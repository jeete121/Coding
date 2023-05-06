#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> ump;
    for (int i = 0; i < nums.size(); i++)
        ump[nums[i]]++;
    int cnt = nums.size() / 3;
    vector<int> res;
    for (auto it = ump.begin(); it != ump.end(); it++)
    {
        if (it->second > cnt)
            res.push_back(it->first);
    }
    return res;
}

int main()
{
    vector<int> nums = {3, 2, 3};
    vector<int> elem = majorityElement(nums);
    cout << "[";
    for (int i = 0; i < elem.size() - 1; i++)
        cout << elem[i] << ",";
    cout << elem[elem.size() - 1] << "]";
    return 0;
}