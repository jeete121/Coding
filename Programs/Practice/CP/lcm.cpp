/*
  lcm=(a*b)/gcd(a,b)
*/#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
       return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<lcm(a,b)<<"\n";
    return 0;
}