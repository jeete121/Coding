#include <bits/stdc++.h>
using namespace std;
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
        swap(arr[i],arr[j]);
     }
    swap(arr[low],arr[j]);
    return j;
}
void quicksort(int arr[],int low,int high)
{
    if(high<=low)
       return;
    int j=partition(arr,low,high);
    quicksort(arr,low,j-1);
    quicksort(arr,j+1,high);
}
int main()
{
  int N;
  cout<<"Enter number of elements:\n";
  cin>>N;
  int arr[N];
  for(int i=0;i<N;i++)
     cin>>arr[i];
  quicksort(arr,0,N-1);
   for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
   return 0;
}