#include <bits/stdc++.h>
using namespace std;



int lowerBound(int arr[], int n,int k) 
{
    //sort the array in ascending order
    sort(arr,arr+n);
    int low =0;
    int high =n;
    while(low != high) 
    {
        //calculate mid point
        int mid = low + (high - low) / 2;
        if (arr[mid] < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
     }

    return low;
}

int main()
{
    int arr[] ={4,3,2,-1};
    int lower = 0;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<lowerBound(arr, n,lower);
    return 0;
}

