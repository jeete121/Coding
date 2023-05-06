#include <bits/stdc++.h>
using namespace std;
//function to merge two
//sorted array
void mergeTwoSortedArray(int arr[],int aux[],int low,int mid,int high)
{
    int k=low,i=low,j=mid+1;
    while(i<=mid&&j<=high)
      {
        //if right subarray value is greater
        //the insert the left subarray into
        //the result
         if(arr[i]<arr[j])
           {
               aux[k++]=arr[i];
               i++;
           }
        //otherwise insert the right subarray value
        //into the result
         else 
           {
               aux[k++]=arr[j];
               j++;
           }
      }
  //if left subarray is remaining and right subaray is
  //over
   while(i<=mid)
         aux[k++]=arr[i++];
  //if right subarray is remaining and left subarray is
  //over
    while(j<=high)
         aux[k++]=arr[j++];
   //store result back to original array
     for(int i=low;i<=high;i++)
        arr[i]=aux[i];
}
//funtion for merge sort
void mergeSort(int arr[],int aux[],int low,int high)
{
   //base case
   if(high<=low)
       return;
   int mid=low+(high-low)/2;
   //left subarray
   mergeSort(arr,aux,low,mid);
   //right subarray
   mergeSort(arr,aux,mid+1,high);
   //merge two sortd array
   mergeTwoSortedArray(arr,aux,low,mid,high);
}
int main()
{
  int arr[]={3,1,4,12,5,13,6};
  int n=sizeof(arr)/sizeof(arr[0]);
  int aux[n];
  mergeSort(arr,aux,0,n-1);
  cout<<"Sorted array is\n";
  for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
    return 0;
}
//Time Complexity:O(nlog(n))
//Space Complexity:O(n)