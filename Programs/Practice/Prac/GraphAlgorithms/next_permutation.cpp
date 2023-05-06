#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int index = -1;
    int n = nums.size();

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }
    }
    index++;
    int j = n - 1;

    while (index < j)
    {
        swap(nums[index], nums[j]);
        j--;
        index++;
    }

    return;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    nextPermutation(nums);

    cout << "[";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}