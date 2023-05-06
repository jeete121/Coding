#include <bits/stdc++.h>
using namespace std;

long long int minMoves(vector<int> &nums)
{
    long long int n = nums.size();
    long long int sum = 0;
    int min1 = INT_MAX;
    for (long long int i = 0; i < n; i++)
    {
        sum += nums[i];
        min1 = min(nums[i], min1);
    }
    return sum - n * min1;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    cout << minMoves(nums);

    return 0;
}