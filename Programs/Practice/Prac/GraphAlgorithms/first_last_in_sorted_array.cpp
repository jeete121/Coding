#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    vector<int> res;
    res.push_back(-1);
    res.push_back(-1);
    if (nums.size() == 0)
        return res;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            int x = mid;
            int y = mid;
            while (x >= 0 && nums[x] == target)
                x--;
            while (y < nums.size() && nums[y] == target)
                y++;
            res.clear();
            res.push_back(x + 1);
            res.push_back(y - 1);
            break;
        }
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return res;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> res = searchRange(nums, target);
    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
        cout << res[i] << ",";
    cout << res[res.size() - 1] << "]";
    return 0;
}