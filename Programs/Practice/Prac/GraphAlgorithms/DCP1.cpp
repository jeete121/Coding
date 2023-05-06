#include <bits/stdc++.h>
using namespace std;

bool isPairSum(vector<int> arr, int k)
{
    //find the size of array
    int n = arr.size();

    //check for every pair
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            //if sum is same as k then
            //return true
            if (arr[i] + arr[j] == k)
            {
                return true;
            }
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

//Time Complexity: O(n^2)
//Space Complexity: O(1)