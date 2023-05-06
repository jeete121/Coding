#include <bits/stdc++.h>
using namespace std;
//Function to sort the given
//array
void bubbleSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
      {
          for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                  {
                      int temp=arr[j];
                      arr[j]=arr[j+1];
                      arr[j+1]=temp;
                  }
            }
      }
}
int main()
{
    int arr[]={3,2,5,4,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    cout<<"Sorted Array is ";
    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
    return 0;
}
//Time Complexity: O(n^2)
//Space Complexity:O(1)