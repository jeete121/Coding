/*
 Find ((N!)mod)P
 Time Complexity O(Plog(N)) where base of log is P
*/
#include <bits/stdc++.h>
using namespace std;
int factmod(int n,int p)
{
    int res=1;
    while(n>1)
     {
         res=(res*((n/p)%2?p-1:1))%p;
         for(int i=2;i<=n%p;i++)
            res=(res*i)%p;
         n/=p;
     }
  return res;
}
int main()
{
    int n,p;
    cin>>n>>p;
    int res=factmod(n,p);
    cout<<res<<"\n";
    return 0;
}