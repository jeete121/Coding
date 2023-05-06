#include <bits/stdc++.h>
using namespace std;

vector<int> quickSort(vector<int> arr)
{
    vector<int> left, right, equal;
    int p = arr[0];
    equal.push_back(p);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > p)
            right.push_back(arr[i]);
        else if (arr[i] < p)
            left.push_back(arr[i]);
        else if (arr[i] == p)
            equal.push_back(arr[i]);
    }
    vector<int> res;
    for (int i = 0; i < left.size(); i++)
        res.push_back(left[i]);
    for (int i = 0; i < equal.size(); i++)
        res.push_back(equal[i]);
    for (int i = 0; i < right.size(); i++)
        res.push_back(right[i]);
    return res;
}

int main()
{
    int n = 5;

    vector<int> arr = {4, 5, 3, 7, 2};
    vector<int> result = quickSort(arr);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << " ";
        }
    }
    return 0;
}
