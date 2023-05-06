#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
    set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        if (st.find(nums[i]) != st.end())
        {
            st.erase(st.find(nums[i]));
        }
        else
            st.insert(nums[i]);
    }
    vector<int> res;
    for (auto it = st.begin(); it != st.end(); it++)
        res.push_back(*it);
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> arr = singleNumber(nums);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}