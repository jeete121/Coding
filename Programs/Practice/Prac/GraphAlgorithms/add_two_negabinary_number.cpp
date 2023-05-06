#include <bits/stdc++.h>
using namespace std;

vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> res;
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());
    int n = arr1.size(), m = arr2.size();
    int i = n - 1, j = m - 1;
    int len = max(n, m);
    int carry = 0;
    for (int i = 0; i < len + 2; i++)
    {
        int x = i < arr1.size() ? arr1[i] : 0;
        int y = i < arr2.size() ? arr2[i] : 0;
        int sum = x + y + carry;
        int r = sum % (-2);
        carry = sum / (-2);
        if (r < 0)
        {
            carry++;
            r += abs(-2);
        }

        res.push_back(r);
    }
    while (res.size() > 1 && res.back() == 0)
    {
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> arr1 = {1, 1, 1, 1, 1};
    vector<int> arr2 = {1, 0, 1};

    vector<int> res = addNegabinary(arr1, arr2);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";

    return 0;
}