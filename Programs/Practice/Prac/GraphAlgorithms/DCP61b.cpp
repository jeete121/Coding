#include <bits/stdc++.h>
using namespace std;

long long int binpower(long long int a,long long int b)
{
    long long int res=1;
    while(b)
     {
         if(b&1)
            res=res*a;
         a=a*a;
         b>>=1;
     }
     return res;
}
int main()
{
    long long int a=2,n=10;
    cout<<binpower(a,n)<<"\n";
    return 0;
}

//Time Complexity : O(log(n))