/*
 Compute a^N in O(log(N)):
*/
#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a,long long b)
{
    long long res=1;
    while(b)
     {
         if(b&1)
           res=res*a;
         a=a*a;
         b=b>>1;
     }
    return res;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    cout<<binpow(a,b)<<"\n";
    return 0;
}