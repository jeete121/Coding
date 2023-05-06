#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int aux[],int low,int mid,int high)
{
    int k=low,i=low,j=mid+1;
    while(i<=mid&&j<=high)
      {
         if(arr[i]<arr[j])
           {
               aux[k++]=arr[i];
               i++;
           }
         else 
           {
               aux[k++]=arr[j];
               j++;
           }
      }
      while(i<=mid)
         aux[k++]=arr[i++];
    while(j<=high)
         aux[k++]=arr[j++];
     for(int i=low;i<=high;i++)
        arr[i]=aux[i];
}
void MergeSort(int arr[],int aux[],int low,int high)
{
  if(high==low)
     return;
     int mid=low+(high-low)/2;
     MergeSort(arr,aux,low,mid);
     MergeSort(arr,aux,mid+1,high);
     merge(arr,aux,low,mid,high);
}
int main()
{
  int N;
  cout<<"Enter number of elements:\n";
  cin>>N;
  int arr[N],aux[N];
  for(int i=0;i<N;i++)
     cin>>arr[i];
  MergeSort(arr,aux,0,N-1);
   for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
   return 0;
}