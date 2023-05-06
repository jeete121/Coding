/*
Compute a^N in O(log(N)):
*/#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a,long long b)
{
    if(b==0)
       return 1;
    long long res=binpow(a,b/2);
    if(b&1)
       return res*res*a;
    else
      return res*res;
    
}
int main()
{
  long long a,b;
  cin>>a>>b;
  cout<<binpow(a,b)<<"\n";
  return 0;
}