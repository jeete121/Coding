#include <bits/stdc++.h>
using namespace std;

int findNumberAppearsOnce(vector<int> &nums)
{
    int first = 0, second = 0, third;
    int n = nums.size();

    //iterate till the end of array
    for (int i = 0; i < n; i++)
    {
        //update second
        second = second | (first & nums[i]);

        //update first
        first = first ^ nums[i];

        //update third
        third = ~(first & second);

        //update first
        first = first & third;
        second = second & third;
    }
    return first;
}

int main()
{
    vector<int> nums = {2, 3, 3, 4, 4, 3, 4};
    cout << findNumberAppearsOnce(nums);
    return 0;
}