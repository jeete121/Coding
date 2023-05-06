#include <bits/stdc++.h>
using namespace std;

//function to find the maximum
//subarray sum
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int max_sum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            max_sum = max(sum, max_sum);
        }
    }
    return max_sum;
}
int main()
{
    vector<int> nums = {34, -50, 42, 14, -5, 86};
    cout << maxSubArray(nums);
    return 0;
}

//Time Complexity: O(n^2)
//Space Complexity: O(1)
