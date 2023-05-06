#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    int n = nums.size();
    if (n == 0)
        return res;
    vector<int> x;
    res.push_back(x);
    for (int i = 0; i < pow(2, n); i++)
    {
        vector<int> y;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)))
                y.push_back(nums[j]);
        }
        if (find(res.begin(), res.end(), y) == res.end())
            res.push_back(y);
    }
    return res;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> sub = subsets(nums);

    cout << "[";
    for (int i = 0; i < sub.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < sub[i].size(); j++)
        {
            cout << sub[i][j];
            if (j != sub[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != sub.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}
