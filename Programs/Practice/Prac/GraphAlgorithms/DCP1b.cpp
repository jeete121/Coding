#include <bits/stdc++.h>
using namespace std;

bool isPairSum(vector<int> arr, int k)
{
    //find the size of array
    int n = arr.size();

    //sort the array
    sort(arr.begin(), arr.end());

    int low = 0, high = n - 1;
    while (low < high)
    {
        //if pair with sum k is found then
        //return true
        if (arr[low] + arr[high] == k)
        {
            return true;
        }
        else if (arr[low] + arr[high] > k)
        {
            high--;
        }
        else
        {
            low++;
        }
    }

    //if no pair then return false
    return false;
}
int main()
{
    vector<int> arr = {10, 15, 3, 7};

    int k = 17;

    if (isPairSum(arr, k))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}

//Time Complexity: O(nlogn)