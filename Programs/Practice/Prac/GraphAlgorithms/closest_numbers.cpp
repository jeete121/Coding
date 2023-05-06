#include <bits/stdc++.h>
using namespace std;

vector<int> closestNumbers(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size(), min1 = INT_MAX;
    vector<int> res;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] < min1)
            min1 = arr[i + 1] - arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] == min1)
        {
            res.push_back(arr[i]);
            res.push_back(arr[i + 1]);
        }
    }
    return res;
}

int main()
{

    int n = 4;

    vector<int> arr = {5, 4, 3, 2};

    vector<int> result = closestNumbers(arr);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << " ";
        }
    }
    cout << "\n";

    return 0;
}
