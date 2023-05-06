#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
vector<int> frequencySort(vector<int> &nums)
{
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
        mp[nums[i]]++;
    vector<pair<int, int>> v;
    for (int i = 0; i < nums.size(); i++)
        v.push_back({mp[nums[i]], nums[i]});
    sort(v.begin(), v.end(), cmp);
    vector<int> res;
    for (int i = 0; i < v.size(); i++)
        res.push_back(v[i].second);
    return res;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 2, 3};
    vector<int> sorted = frequencySort(nums);
    cout << "[";
    for (int i = 0; i < sorted.size() - 1; i++)
        cout << sorted[i] << ",";
    cout << sorted[sorted.size() - 1] << "]";
    return 0;
}