#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int findGCD(vector<int> &nums)
{

    int minElement = nums[0], maxElement = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        minElement = min(minElement, nums[i]);
        maxElement = max(maxElement, nums[i]);
    }

    return gcd(minElement, maxElement);
}

int main()
{
    vector<int> nums = {2, 5, 6, 9, 10};

    cout << findGCD(nums) << "\n";

    return 0;
}