#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, 
         vector<int> &nums2)
{
    vector<int> v;
    stack<int> st;
    int n = nums2.size();
    int m = nums1.size();
    if (n == 0 || m == 0)
        return v;
    map<int, int> mp;
    st.push(nums2[n - 1]);
    mp[nums2[n - 1]] = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        //while stack is not empty and stack top is
        //less than current value then pop from 
        //stack
        while (!st.empty() && st.top() <= nums2[i])
            st.pop();

        //if stack is empty then add -1
        if (st.empty())
            mp[nums2[i]] = -1;

        //else add stack top element
        else
            mp[nums2[i]] = st.top();

        //push current element into the stack
        st.push(nums2[i]);
    }

    for (int i = 0; i < m; i++)
        v.push_back(mp[nums1[i]]);
    return v;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> NGE = nextGreaterElement(nums1, nums2);
    cout << "[";
    for (int i = 0; i < NGE.size() - 1; i++)
        cout << NGE[i] << ",";
    cout << NGE[NGE.size() - 1] << "]";

    return 0;
}