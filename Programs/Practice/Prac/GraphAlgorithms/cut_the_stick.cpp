#include <bits/stdc++.h>
using namespace std;

vector<int> cutTheSticks(vector<int> arr)
{
    int n = arr.size();
    vector<int> res;
    sort(arr.begin(), arr.end());
    res.push_back(n);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            res.push_back(n - i);
        }
    }
    return res;
}
int main()
{
    int n = 6;
    vector<int> arr = {5, 4, 4, 2, 2, 8};
    vector<int> res = cutTheSticks(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "\n";
    }
    return 0;
}
