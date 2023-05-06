#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    double maxAns = INT_MIN;
    double sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    maxAns = max(maxAns, sum / k);
    for (int i = k; i < nums.size(); i++)
    {
        sum += nums[i];
        sum -= nums[i - k];
        maxAns = max(maxAns, sum / k);
    }
    return maxAns;
}

int main()
{
     vector<int> nums={1,12,-5,-6,50,3};
     int  k = 4;

     cout<<findMaxAverage(nums,k);

     return 0;
}