#include <bits/stdc++.h>
using namespace  std;
/*
This is to find (a^b)%m for big numbers efficiently
Time Complexity: O(log(b))
*/

long long int binpower(long long int a,long long int b,long long int m)
{
    a%=m;
    long long int res=1;
    while(b>0)
    {
      if(b&1)
         res=((res)%m*(a)%m)%m;
      a=((a)%m*(a)%m)%m;
      b>>=1;
    }
  return res%m;
    
}
 int main()
{
    long long int a,b,m;
    cin>>a>>b>>m;
    cout<<binpower(a,b,m)<<"\n";
    return 0;
}