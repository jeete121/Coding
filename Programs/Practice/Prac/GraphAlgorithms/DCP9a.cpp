#include <bits/stdc++.h>
using namespace std;

int findMaximumNonAdjacentSum(vector<int> &arr)
{
    int len = arr.size();
    if (len == 0)
    {
        return 0;
    }

    if (len == 1)
    {
        return arr[0];
    }

    int sum[len];
    sum[len - 1] = arr[len - 1];
    sum[len - 2] = max(arr[len - 1], arr[len - 2]);

    for (int i = len - 3; i >= 0; i--)
    {
        sum[i] = max(arr[i] + sum[i + 2], sum[i + 1]);
    }

    return sum[0];
}

int main()
{
    vector<int> arr = {2, 4, 6, 2, 5};

    cout << findMaximumNonAdjacentSum(arr);

    return 0;
}
//Time Complexity: O(n)
//Space Complexity: O(n)