#include <bits/stdc++.h>
using namespace std;

//function to find the maximum product
//of three numbers in the array
//array must contains at least 3 elements
int maximumProduct(int arr[], int n)
{

    sort(arr, arr + n);

    int max1 = arr[n - 1];
    int max2 = arr[n - 2];
    int max3 = arr[n - 3];

    int min1 = arr[0];
    int min2 = arr[1];
    //case 1: maximum=max1*max2*max3
    //case 2: maximum =min1*min2*max1
    return max(min1 * min2 * max1, max1 * max2 * max3);
}

int main()
{
    //array must contains 3 elements
    int arr[] = {-10, -10, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    //i.e (-10)*(-10)*5
    int maximum = maximumProduct(arr, n);
    cout << maximum << "\n";
    return 0;
}

//Time Complexity: O(nlogn)