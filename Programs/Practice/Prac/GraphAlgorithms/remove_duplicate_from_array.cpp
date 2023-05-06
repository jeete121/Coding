#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int> nums)
{
    sort(nums.begin(),nums.end());
    int l = 0;
    int i = 0;
    int n = nums.size();
    while (i < n)
    {
        nums[l++] = nums[i];
        i++;
        while (i < n && nums[i] == nums[i - 1])
        {
            i++;
        }
    }
    nums.resize(l);
    return nums;
}
int main()
{
    vector<int> arr = {1, 3, 4, 2, 3, 4, 3};

    vector<int> res = removeDuplicates(arr);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}