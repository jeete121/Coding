#include <bits/stdc++.h>
using namespace std;

bool kLengthApart(vector<int> &nums, int k)
{

    int n = nums.size();

    int i = 0;
    while (i < n)
    {
        int cnt = 0;
        while (i < n && nums[i] == 0)
        {
            i++;
        }
        if (i == n)
            return true;
        i++;
        if (i == n)
            return true;
        while (i < n && nums[i] == 0)
        {
            cnt++;
            i++;
        }
        if (i == n)
            return true;
        if (cnt < k)
            return false;
    }
    return true;
}

int main()
{
    vector<int> nums = {1, 0, 0, 0, 1, 0, 0, 1};
    int k = 2;

    if (kLengthApart(nums, k))
    {
        cout << "true";
    }
    else
        cout << "false";

    return 0;
}