#include <bits/stdc++.h>
using namespace std;
/*
This is to find the GCD of two numbers in recursive
Time Complexity: O(log(min(a,b)))
*/

long long int gcd(long long int a,long long int b)
{
    if(b==0)
       return a;
    return gcd(b,a%b);
}
int main()
{
    long long int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<"\n";
    return 0;
}