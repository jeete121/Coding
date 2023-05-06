#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> res;
    set<int> st;
    for (int i = 0; i < nums.size(); i++)
        st.insert(nums[i]);
    for (int i = 1; i <= nums.size(); i++)
        if (st.find(i) == st.end())
            res.push_back(i);
    return res;
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    vector<int> res = findDisappearedNumbers(nums);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}