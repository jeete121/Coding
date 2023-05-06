#include <bits/stdc++.h>
using namespace std;
//Function to sort the given
//array
void selectionSort(int arr[],int n)
{
    int minIndex;
    for(int i=0;i<n-1;i++)
      {
          minIndex=i;
          for(int j=i+1;j<n;j++)
            {
                if(arr[j]<arr[minIndex])
                  {
                     minIndex=j;
                  }
            }
         int temp=arr[minIndex];
         arr[minIndex]=arr[i];
         arr[i]=temp;
      }
}
int main()
{
    int arr[]={3,2,5,4,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    cout<<"Sorted Array is ";
    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
    return 0;
}
//Time Complexity: O(n^2)
//Space Complexity:O(1)