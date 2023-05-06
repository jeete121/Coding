#include <bits/stdc++.h>
using namespace std;

//function to find the peak
//element index in the array 
//of valid mountain array
int peakIndexInMountainArray(int arr[],int n) 
{
    int low=0,high=n-1;
    int mid=0;
    while(low<high)
     {
         mid=low+(high-low)/2;

         //if mid is last or first then return
         //mid
         if(mid==0||mid==n-1)
            return mid;
        //if mid element is greater than left
        //and right then return mid
         if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
               return mid;
        
        //if mid greter then left and mid less
        //than right move low to mid
         if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1])
                low=mid;
        
        //else move high to mid
           else
              high=mid;
     }
 return mid;
        
}
int main()
{
    int arr[] = { 3, 4, 5, 1 };
    int n=sizeof(arr)/sizeof(arr[0]);
    int index = peakIndexInMountainArray(arr,n);
    cout<<index;
    return 0;
}