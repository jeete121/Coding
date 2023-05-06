#include <bits/stdc++.h>
using namespace std;
bool subarray(int arr[], int n, int sum)
{
    int currSum = arr[0], start = 0, i;
    for (i = 1; i <= n; i++)
    {
        while (currSum > sum && start < i - 1)
        {
            currSum -= arr[start];
            start++;
        }
        if (currSum == sum)
            return true;
        if (i < n)
            currSum += arr[i];
    }
    return false;
}
int main()
{

    int n = 5, k = 12;

    int arr[n] = {1, 3, 4, 5, 2};

    bool ans = subarray(arr, n, k);
    if (ans == true)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}