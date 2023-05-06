#include <bits/stdc++.h>
using namespace std;

int findSpecialInteger(vector<int> &arr)
{
    int max1 = INT_MIN;
    int n = arr.size();
    int i = 0;
    int x = 0;
    if (n == 1)
        return arr[0];
    while (i < n - 1)
    {
        int cnt = 1;
        while (i < n - 1 && arr[i] == arr[i + 1])
        {
            i++;
            cnt++;
        }
        if (cnt > x)
        {
            x = cnt;
            max1 = max(max1, arr[i]);
        }
        i++;
    }
    return max1;
}

int main()
{
    vector<int> arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    cout << findSpecialInteger(arr);
    return 0;
}