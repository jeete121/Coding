#include <bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int> &nums)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < nums.size(); i++)
        v.push_back({nums[i], i});
    sort(v.begin(), v.end());
    vector<string> res(nums.size());
    //res.resize(nums.size());
    int l = 4;
    int n = nums.size();
    if (n == 0)
        return res;

    res[v[n - 1].second] = "Gold Medal";
    if (n == 1)
        return res;
    res[v[n - 2].second] = "Silver Medal";
    if (n == 2)
        return res;
    res[v[n - 3].second] = "Bronze Medal";
    if (n == 3)
        return res;
    for (int i = nums.size() - 4; i >= 0; i--)
    {
        res[v[i].second] = to_string(l++);
    }
    return res;
}

int main()
{
    vector<int> score = {5, 4, 3, 2, 1};

    vector<string> res = findRelativeRanks(score);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {

        cout << res[i];
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}