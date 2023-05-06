#include <bits/stdc++.h>
using namespace std;
//Function to sort the given
//array
void insertionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
      {
          int temp=arr[i];
          int j=i;
          while(j>0&&arr[j-1]>temp)
            {
               arr[j]=arr[j-1];
               j=j-1;
            }
          arr[j]=temp;
      }
}
int main()
{
    int arr[]={3,2,5,4,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);
    cout<<"Sorted Array is ";
    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
    return 0;
}
//Time Complexity: O(n^2)
//Space Complexity:O(1)