#include <bits/stdc++.h>
using namespace std;
/*
This is to find a^n efficiently iterative
Time Complexity: O(log(n))
*/
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
    long long int a,n;
    cin>>a>>n;
    cout<<binpower(a,n)<<"\n";
    return 0;
}