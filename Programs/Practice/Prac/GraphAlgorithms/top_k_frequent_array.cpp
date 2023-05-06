#include <bits/stdc++.h>
using namespace std;

bool static cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second > b.second);
}
vector<int> topKFrequent(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int i = 0;
    int n = nums.size();
    vector<int> res;
    vector<pair<int, int>> v;
    int cnt = 1;
    while (i < n - 1)
    {
        if (nums[i] == nums[i + 1])
        {
            cnt++;
            i++;
        }
        else
        {
            v.push_back({nums[i], cnt});
            cnt = 1;
            i++;
        }
    }
    v.push_back({nums[i], cnt});
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < k; i++)
        res.push_back(v[i].first);
    return res;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> freq = topKFrequent(nums, k);
    cout << "[";
    for (int i = 0; i < freq.size() - 1; i++)
        cout << freq[i] << ",";
    cout << freq[freq.size() - 1] << "]";
}