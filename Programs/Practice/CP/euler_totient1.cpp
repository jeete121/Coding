/*
 Count coprime of N from 1 to N
 Coprimes are those numbers whose gcd is 1 
 Euler totient method
 Time Complexity: O(sqrt(N))
*/
#include <bits/stdc++.h>
using namespace std;
int phi(int n)
{
    int res=n;
    for(int i=2;i*i<=n;i++)
      {
          if(n%i==0)
            {
                while(n%i==0)
                   n/=i;
               res-=res/i;
            }
      }
    if(n>1)
       res-=res/n;
   return res;
}
int main()
{
    int n;
    cin>>n;
    int res=phi(n);
    cout<<res<<"\n";
    return 0;
}