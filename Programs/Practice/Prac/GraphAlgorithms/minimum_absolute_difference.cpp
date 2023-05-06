#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int min1 = INT_MAX;
    vector<vector<int>> res;
    for (int i = 1; i < arr.size(); i++)
        min1 = min(arr[i] - arr[i - 1], min1);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - arr[i - 1] == min1)
        {
            vector<int> x;
            x.push_back(arr[i - 1]);
            x.push_back(arr[i]);
            res.push_back(x);
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {4, 2, 1, 3};
    vector<vector<int>> res = minimumAbsDifference(arr);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (j != res[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}