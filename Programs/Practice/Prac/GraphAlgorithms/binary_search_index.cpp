#include <bits/stdc++.h>
using namespace std;
//Function to find the element in array
int binarySearch(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        //if target is same as mid element
        if (arr[mid] == target)
            return mid;
        //if target is large then mid
        else if (arr[mid] < target)
            low = mid + 1;
        //if target is small then mid
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[] = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = binarySearch(arr, n, target);
    cout << index;
    return 0;
}
//Time Complexity: O(log(n))
//Space Complexity:O(1)