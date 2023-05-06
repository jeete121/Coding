#include <bits/stdc++.h>
using namespace std;

void duplicateZeros(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            res.push_back(0);
            if (res.size() == n)
            {
                arr = res;
                break;
            }
            else
            {
                res.push_back(0);
            }
            if (res.size() == n)
            {
                arr = res;
                break;
            }
        }
        else
        {
            res.push_back(arr[i]);
            if (res.size() == n)
            {
                arr = res;
                break;
            }
        }
    }
}

int main()
{
    vector<int> nums = {1, 0, 2, 3, 0, 4, 5, 0};
    duplicateZeros(nums);
    cout << "[";
    for (int i = 0; i < nums.size() - 1; i++)
        cout << nums[i] << ",";
    cout << nums[nums.size() - 1] << "]";
    return 0;
}