#include <bits/stdc++.h>
using namespace std;

vector<int> circularArrayRotation(vector<int> arr, int k, vector<int> queries)
{
    vector<int> res;
    int n = arr.size();
    k = k % n;
    int temp[n - k];
    for (int i = 0; i < n - k; i++)
    {
        temp[i] = arr[i];
    }
    int l = 0;
    for (int i = n - k; i < n; i++)
    {
        arr[l++] = arr[i];
    }
    for (int i = 0; i < n - k; i++)
    {
        arr[l++] = temp[i];
    }
    for (int i = 0; i < n; i++)
    {
        int j = queries[i];
        res.push_back(arr[j]);
    }
    return res;
}
int main()
{
    int n = 3, k = 2, q = 3;
    vector<int> arr = {1, 2, 3};
    vector<int> queries = {0, 1, 2};
    vector<int> res = circularArrayRotation(arr, k, queries);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "\n";
    }
    return 0;
}
