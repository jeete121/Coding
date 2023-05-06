#include <bits/stdc++.h>
using namespace std;

int minAbsoluteDifferenceSum(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int n = arr.size();

    if (n == 1)
        return arr[0];

    int sum = abs(arr[1] - arr[0]);
    sum += abs(arr[n - 1] - arr[n - 2]);

    for (int i = 1; i < n - 1; i++)
    {
        sum += min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
    }

    return sum;
}
int main()
{

    vector<int> arr = {1, 3, 8, 4, 5};

    cout << minAbsoluteDifferenceSum(arr);

    return 0;
}