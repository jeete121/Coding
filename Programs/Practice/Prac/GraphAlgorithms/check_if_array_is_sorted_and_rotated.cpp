#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums)
{
    //find position of minimum element
    int k = min_element(nums.begin(), nums.end()) - nums.begin();

    //length of array
    int n = nums.size();

    int j;
    if (k == 0)
    {
        j = n - 1;
        while (j > 0 && nums[j] == nums[k])
        {
            j--;
        }
    }
    else
    {
        j = k - 1;
    }
    int i = k;
    while (i != j)
    {
        if (nums[i] > nums[(i + 1) % n])
        {
            return false;
        }
        i = (i + 1) % n;
    }
    return true;
}

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};

    if (check(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}