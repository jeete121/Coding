#include <bits/stdc++.h>
using namespace std;

//function to find the maximum product
//of three numbers in the array
//array must contains at least 3 elements
int maximumProduct(int arr[], int n)
{
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

    //find the maximum three elements
    for (int i = 0; i < n; i++)
    {

        //update max1,max2 and man3
        if (arr[i] > max1)
        {
            max3 = max(max2, max3);
            max2 = max(max2, max1);
            max1 = arr[i];
        }

        //update max2 and  max3
        else if (arr[i] > max2)
        {
            max3 = max(max2, max3);
            max2 = arr[i];
        }

        //update max3
        else if (arr[i] > max3)
            max3 = arr[i];
    }
    int min1 = INT_MAX, min2 = INT_MAX;

    //find the minimum two elements
    for (int i = 0; i < n; i++)
    {

        //update min1 and min2
        if (arr[i] < min1)
        {
            min2 = min(min1, min2);
            min1 = arr[i];
        }

        //update min2
        else if (arr[i] < min2)
            min2 = arr[i];
    }
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

//Time Complexity: O(n)

