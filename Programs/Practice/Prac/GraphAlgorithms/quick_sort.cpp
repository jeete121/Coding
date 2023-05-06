#include <bits/stdc++.h>
using namespace std;
//function to partition the array into 
//two half
int partition(int arr[],int low,int high)
{
    int i=low,j=high+1;
    while(true)
     {
        while(arr[++i]<arr[low])
          if(i==high)
             break;
        while(arr[low]<arr[--j])
           if(j==low)
              break;
        if(i>=j)
          break;
        //swapping of i and j
        swap(arr[i],arr[j]);
     }
    //swapping of low and j
    swap(arr[low],arr[j]);
    return j;
}
//function for quick sort
void quicksort(int arr[],int low,int high)
{
    //base case
    if(high<=low)
       return;
    int j=partition(arr,low,high);
    quicksort(arr,low,j-1);
    quicksort(arr,j+1,high);
}
int main()
{
  int arr[]={3,1,4,12,6,9,2};
  int n=sizeof(arr)/sizeof(arr[0]);
  quicksort(arr,0,n-1);
  cout<<"Array after sorting is\n";
  for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
   return 0;
}
//Average: Time Complexity:O(nlog(n))
//Worst :Time Complexity:O(n^2)
