/*
 Nth fibonacci number:
 Time: O(log(N))
*/
#include <bits/stdc++.h>
using namespace std;
pair<int,int> fib(int n)
{
    if(n==0)
      return {0,1};
    auto p=fib(n>>1); //n becomes n/2 every time
    int c=p.first*(2*p.second-p.first);
    int d=p.first*p.first+p.second*p.second;
    if(n&1)
       return {d,c+d};
    return {c,d};
    
}
int main()
{
    int n;
    cin>>n;
    pair<int,int> res=fib(n);
    cout<<res.first<<"\n";
    return 0;
}