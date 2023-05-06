#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> res;
    int p = 0;
    bool flag = false;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            flag = true;
            p = i;
            break;
        }
    }
    int i = p;
    int j = p - 1;
    if (flag == false)
        j = nums.size() - 1;
    while (j >= 0 && i < nums.size())
    {
        if (nums[i] * nums[i] < nums[j] * nums[j])
        {
            res.push_back(nums[i] * nums[i]);
            i++;
        }
        else
        {
            res.push_back(nums[j] * nums[j]);
            j--;
        }
    }
    while (j >= 0)
    {
        res.push_back(nums[j] * nums[j]);
        j--;
    }
    while (i < nums.size() && flag)
    {
        res.push_back(nums[i] * nums[i]);
        i++;
    }
    return res;
}
int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> res = sortedSquares(nums);

    cout << "[";

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}