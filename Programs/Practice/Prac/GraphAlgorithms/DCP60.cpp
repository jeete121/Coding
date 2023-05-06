#include <bits/stdc++.h>
using namespace std;

bool isPartitionSubstes(vector<int> &arr, int n, int sum)
{
    // if n is greater than size of array or
    //n is less than 0 then return false
    if (n >= arr.size() || n < 0)
        return false;

    //if sum is less than 0 then return false
    if (sum < 0)
        return false;

    //if sum becomes 0 then return true
    if (sum == 0)
        return true;
    return isPartitionSubstes(arr, n - 1, sum - arr[n]) ||
           isPartitionSubstes(arr, n - 1, sum);
}
int main()
{
    vector<int> arr = {15, 5, 20, 10, 35, 15, 10};

    int sum = 0;

    //find sum of array elements
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    if (isPartitionSubstes(arr, arr.size() - 1, sum / 2))
        cout << "true";
    else
        cout << "false";

    return 0;
}