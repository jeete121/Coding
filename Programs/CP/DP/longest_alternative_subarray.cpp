#include <bits/stdc++.h>
using namespace std;
void longest_alt_subarray(int arr[],int n)
{
  int max_len=0,curr_len=1,index=0;
  for(int i=1;i<n;i++)
  {
    if(arr[i]*arr[i-1]<0)
    {
      curr_len++;
       if(curr_len>max_len)
       {
           max_len=curr_len;
           index=i;
       }
    }
    else
        curr_len=1;
  }
  for(int i=index-max_len+1;i<=index;i++)
      cout<<arr[i]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    longest_alt_subarray(arr,n);
}
