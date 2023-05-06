#include <bits/stdc++.h>
using namespace std;

bool isGoodArray(vector<int> &nums)
{

    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = __gcd(nums[i], ans);
    }
    if (ans == 1)
        return true;
    return false;
}

int main()
{
    vector<int> nums = {12, 5, 7, 23};

    if (isGoodArray(nums))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}