#include <bits/stdc++.h>
using namespace std;

int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
    int n = arr1.size(), m = arr2.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        int flag = 1;
        for (j = 0; j < m; j++)
        {
            if (abs(arr1[i] - arr2[j]) <= d)
            {
                flag = 0;
                break;
            }
        }
        cnt += flag;
    }
    return cnt;
}

int main()
{
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;
    cout << findTheDistanceValue(arr1, arr2, d);
    return 0;
}