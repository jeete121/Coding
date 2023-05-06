#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007
long long binpow(long long a,long long b)
{
    long long res=1;
    while(b)
     {
         if(b&1)
           res=(res*a)%MOD;
         a=(a*a)%MOD;
         b=b>>1;
     }
     return res%MOD;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    long long res=binpow(a,b)%MOD;
    cout<<res%MOD<<"\n";
    return 0;
}