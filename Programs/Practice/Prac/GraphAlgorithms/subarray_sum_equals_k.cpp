#include <bits/stdc++.h>
using namespace std;

//find the number of subarray whose
//sum is equal to k
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> ump;
    int sum = 0, res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == k)
            res++;
        if (ump.find(sum - k) != ump.end())
            res += ump[sum - k];
        ump[sum]++;
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << subarraySum(nums, k);
    return 0;
}