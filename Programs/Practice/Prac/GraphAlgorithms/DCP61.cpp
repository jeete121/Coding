#include <bits/stdc++.h>
using namespace std;


long long int binpower(long long int a,long long int n)
{
    if(n==0)
       return 1;
    long long int res=binpower(a,n/2);
    if(n&1)
       return res*res*a;
    else
        return res*res;
    
}
int main()
{
    long long int a=2,n=10;
    
    cout<<binpower(a,n)<<"\n";

    return 0;
}