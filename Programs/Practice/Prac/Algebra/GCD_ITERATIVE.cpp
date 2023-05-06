#include <bits/stdc++.h>
using namespace std;
/*
This is to find GCD of two numbers iteratively
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
int main()
{
    long long int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<"\n";
    return 0;
}