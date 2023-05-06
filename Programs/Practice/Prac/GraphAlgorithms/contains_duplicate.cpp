#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{

    set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        if (st.find(nums[i]) != st.end())
            return true;
        st.insert(nums[i]);
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};

    if (containsDuplicate(nums))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}