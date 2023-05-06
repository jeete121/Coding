#include <bits/stdc++.h>
using namespace std;
/*
This is to find the a^n efficiently recursively
Time Complexity: O(log(n))
*/
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
    long long int a,n;
    cin>>a>>n;
    cout<<binpower(a,n)<<"\n";
}