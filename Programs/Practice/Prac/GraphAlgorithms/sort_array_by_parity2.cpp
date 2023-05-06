#include <bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParityII(vector<int> &A)
{
    vector<int> v, v1;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
            v.push_back(A[i]);
        else
            v1.push_back(A[i]);
    }
    int l = 0, k = 0;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            res.push_back(v1[l++]);
        else
            res.push_back(v[k++]);
    }
    return res;
}

int main()
{
    vector<int> nums = {4, 2, 5, 7};
    nums = sortArrayByParityII(nums);
    cout << "[";
    for (int i = 0; i < nums.size() - 1; i++)
        cout << nums[i] << ",";
    cout << nums[nums.size() - 1] << "]";
    return 0;
}