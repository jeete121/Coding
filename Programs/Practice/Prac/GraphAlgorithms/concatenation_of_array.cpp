#include <bits/stdc++.h>
using namespace std;

vector<int> getConcatenation(vector<int> &nums)
{

    int n = nums.size();
    vector<int> ans(2 * n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = nums[i];
        ans[i + n] = nums[i];
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 1};

    vector<int> ans = getConcatenation(nums);

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << "]";
    return 0;
}