#include <bits/stdc++.h>
using namespace std;

//function to remove the element
//from given position of the given array
int removeElement(int arr[],int position,int n)
{
  int l=0;
  for(int i=0;i<n;i++)
    {
        //if arr[i]==target
        //continue
        if(i==position)
          continue;

        //else push that element at the
        //current position
        else
          arr[l++]=arr[i];
    }
   return l;
}
int main()
{
    int arr[]={3,2,1,3,4,5};
    int position=2;
    int n=sizeof(arr)/sizeof(arr[0]);
    n=removeElement(arr,position,n);
    for(int i=0;i<n;i++) 
       cout<<arr[i]<<" ";
    return 0;
}