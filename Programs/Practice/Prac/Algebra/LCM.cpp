#include <bits/stdc++.h>
using namespace std;
/*
Find the LCM of a and b
Time Complexity: O(log(min(a,b)))
*/
long long int gcd(long long int a,long long int b)
{
    while(b)
     {
         a%=b;
         swap(a,b);
     }
     return a;
}
long long int LCM(long long int a,long long b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    long long int a,b;
    cin>>a>>b;
    cout<<LCM(a,b)<<"\n";
    return 0;
}