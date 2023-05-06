
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < nums.size(); i++)
        v.push_back({nums[i], i});

    //sort the array
    sort(v.begin(), v.end());

    int i = 0, j = nums.size() - 1;
    vector<int> res;
    while (i < j)
    {
        if ((v[i].first + v[j].first == target))
        {
            res.push_back(v[i].second);
            res.push_back(v[j].second);
            break;
        }
        else if (v[i].first + v[j].first > target)
            j--;
        else
            i++;
    }
    sort(res.begin(), res.end());
    return res;
}
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    cout << "[" << ans[0] << "," << ans[1] << "]";
    return 0;
}