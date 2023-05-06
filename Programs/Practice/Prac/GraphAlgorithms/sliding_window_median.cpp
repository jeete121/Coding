#include <bits/stdc++.h>
using namespace std;

multiset<double> st;
double median()
{
    double a = *next(st.begin(), st.size() / 2 - 1);
    double b = *next(st.begin(), st.size() / 2);
    if (st.size() & 1)
        return b;
    return (a + b) / 2;
}
vector<double> medianSlidingWindow(vector<int> &nums, int k)
{
    st.clear();
    vector<double> res;
    for (int i = 0; i < k; i++)
        st.insert(nums[i]);
    for (int i = k; i < nums.size(); i++)
    {
        res.push_back(median());
        st.erase(st.find(nums[i - k]));
        st.insert(nums[i]);
    }
    res.push_back(median());
    return res;
}
int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<double> median = medianSlidingWindow(nums, k);

    cout << "[";
    for (int i = 0; i < median.size(); i++)
    {
        cout << median[i];
        if (i != median.size() - 1)
            cout << ",";
    }
    cout << "]";
}