#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> v;
    set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        int x = st.size();
        st.insert(nums[i]);
        if (x == st.size())
            v.push_back(nums[i]);
    }
    return v;
}

int main()
{
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> res = findDuplicates(arr);
    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
        cout << res[i] << ",";
    cout << res[res.size() - 1] << "]";
    return 0;
}