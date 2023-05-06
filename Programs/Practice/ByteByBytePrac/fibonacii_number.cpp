#include<bits/stdc++.h>
using namespace std;
long long fibonacci(int x,vector<long long> &cache)
{
    if(cache[x]>-1)
       return cache[x];
    cache[x]=fibonacci(x-1,cache)+fibonacci(x-2,cache);
    return cache[x];
}
long long fibonacci(int x)
{
    if(x<0)
       return -1;
    if(x==0)
       return 0;
    vector< long long > cache(x+1,-1);
    cache[0]=0;
    cache[1]=1;
   return fibonacci(x,cache);
}
   
int main()
{
  int n;
  cin>>n;
  cout<<fibonacci(n)<<"\n";
  return 0;
}