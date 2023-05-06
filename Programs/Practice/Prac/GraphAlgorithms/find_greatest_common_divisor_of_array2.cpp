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

    sort(nums.begin(), nums.end());
    int minElement = nums[0], maxElement = nums[nums.size() - 1];

    return gcd(minElement, maxElement);
}

int main()
{
    vector<int> nums = {2, 5, 6, 9, 10};

    cout << findGCD(nums) << "\n";

    return 0;
}