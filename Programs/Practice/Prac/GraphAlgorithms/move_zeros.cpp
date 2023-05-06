#include <bits/stdc++.h>
using namespace std;

//function to move all 
//zeros to the end of
//the array
void moveZeroes(vector<int>& arr) 
{
        int n=arr.size();
        int l=0;
        for(int i=0;i<n;i++)
         {
            if(arr[i]!=0)
                  arr[l++]=arr[i];
         }
        while(l<n)
               arr[l++]=0;
}
int main()
{
  vector<int> arr={0,1,0,3,12};
  moveZeroes(arr);
  for(int i=0;i<arr.size();i++)
     cout<<arr[i]<<" ";
  return 0;
}