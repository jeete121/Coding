#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int res = 0;
    int cnt = 0;
    int n = nums.size();
    if (n == 0)
        return res;
    int i = 0;
    while (i < n)
    {
        if (nums[i] == 1)
        {
            cnt++;
            i++;
        }
        else
        {
            res = max(res, cnt);
            i++;
            cnt = 0;
        }
    }
    res = max(res, cnt);
    return res;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout << findMaxConsecutiveOnes(nums);

    return 0;
}