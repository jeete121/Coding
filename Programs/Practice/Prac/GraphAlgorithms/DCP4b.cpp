#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        //if negative then continue to
        //next index
        if (nums[i] < 0)
        {
            continue;
        }
        int pos = nums[i] - 1;
        while (pos != i)
        {
            if (pos < 0 || pos >= n || nums[pos] == nums[i])
                break;
            swap(nums[i], nums[pos]);
            pos = nums[i] - 1;
        }
    }
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (nums[i] - 1 != i)
        {
            return i + 1;
        }
    }
    return i + 1;
}
int main()
{
    vector<int> arr = {3, 4, -1, 1};

    cout << firstMissingPositive(arr);

    return 0;
}

//Time Compplexity :O(n)
//Space Complexity :O(1)