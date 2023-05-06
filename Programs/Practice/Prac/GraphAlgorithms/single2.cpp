#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int first = 0, second = 0, third;
    int n = nums.size();

    //iterate till the end of array
    for (int i = 0; i < n; i++)
    {
        //update second
        second = second | (first & nums[i]);
        first = first ^ nums[i];
        third = ~(first & second);
        first = first & third;
        second = second & third;
    }
    return first;
}

int main()
{
    vector<int> nums = {2, 2, 3, 2};
    cout << singleNumber(nums);
    return 0;
}