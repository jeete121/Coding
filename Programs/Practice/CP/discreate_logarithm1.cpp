/*
The discrete logarithm is an integer x solving the equation:
ax≡b(mod m)
where a and m are relatively prime
Time Complexity: O(sqrt(m)log(m))
*/
#include <bits/stdc++.h>
using namespace std;
int powmod(int a,int  b,int m)
{
    int res=1;
    while(b>0)
     {
         if(b&1)
         {
           res=(res*111*a)%m;
         }
        a=(a*111*a)%m;
        b>>=1;
     }
    return res;
}
int solve(int a,int b,int m)
{
  int n=(int )sqrt(m+.0)+1;
  map<int,int> vals;
  for(int p=n;p>=1;p--)
     vals[powmod(a,p*n,m)]=p;
  for(int q=0;q<=n;q++)
    {
        int cur=(powmod(a,q,m)*111*b)%m;
        if(vals.count(cur))
          {
              int ans=vals[cur]*n-q;
              return ans;    
          }
    }
    return -1;
}
int main()
{
    int a,b,m;
    cin>>a>>b>>m;
    int res=solve(a,b,m);
    cout<<res<<"\n";
    return 0;
}