#include <bits/stdc++.h>
using namespace std;

int xorOperation(int n, int start) 
{
    if(n==0)
          return 0;
    int nums[n];
    for(int i=0;i<n;i++)
    {
        nums[i]=start+2*i;
    }
    int res=nums[0];
    for(int i=1;i<n;i++)
           res=res^nums[i];
        return res;
}
int main()
{
   int n=5,start=0;

   //array 0,2,4,6,8
   cout<<xorOperation(n,start);
   return 0;
}

