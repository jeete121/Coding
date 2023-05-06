#include <bits/stdc++.h>
using namespace std;



vector<int> replaceElements(vector<int>& arr) 
{
    int n=arr.size();
    if(n==0)
       return arr;
    int max1=arr[n-1];
    arr[n-1]=-1;
    for(int i=n-2;i>=0;i--)
      {
          int x=arr[i];
          arr[i]=max1;
          max1=max(max1,x);
      }
        return arr;
}
int main()
{
   vector<int> arr ={17,18,5,4,6,1};
   arr=replaceElements(arr);
   for(int i=0;i<arr.size();i++)
      cout<<arr[i]<<" ";
   return 0;
}
