#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
bool isPartitionSubstes(vector<int> &arr, int n, int sum)
{

    //if n is greater than size of array or
    //n is less than 0 then return false
    if (n >= arr.size() || n < 0)
        return false;

    //if sum is less than 0 then return false
    if (sum < 0)
        return false;

    //if sum becomes 0 then return true
    if (sum == 0)
        return true;

    //if already calculated
    if (dp[n][sum] != -1)
        return dp[n][sum];

    //else calculate
    else
        dp[n][sum] =
            isPartitionSubstes(arr, n - 1, sum - arr[n]) ||
            isPartitionSubstes(arr, n - 1, sum);

    //return the dp[n][sum]
    return dp[n][sum];
}
int main()
{
    vector<int> arr = {15, 5, 20, 10, 35, 15, 10};

    int sum = 0;

    //find the sum of array elements
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    memset(dp, -1, sizeof(dp));

    if (isPartitionSubstes(arr, arr.size() - 1, sum / 2))
        cout << "true";
    else
        cout << "false";

    return 0;
}