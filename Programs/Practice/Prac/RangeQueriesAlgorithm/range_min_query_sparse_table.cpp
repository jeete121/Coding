#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001
#define K 25
long long int log1[MAXN+1];
long long int st[MAXN][K+1];
long long int arr[1000001];
void log_init()
{
    log1[1]=0;
    for(long long int i=2;i<=MAXN;i++)
       log1[i]=log1[i/2]+1;
}
void init(long long int n)
{
    for(long long int i=0;i<n;i++)
       st[i][0]=arr[i];
   for(long long int j=1;j<=K;j++)
      {
          for(long long int i=0;i+(1<<j)<=n;i++)
             st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
      }
}
long long int query(long long int l,long long int r)
{
    long long int j=log1[r-l+1];
    long long int min1=min(st[l][j],st[r-(1<<j)+1][j]);
    return min1;
}
int main()
{
    long long int n,q;
    cin>>n>>q;
    for(long long int i=0;i<n;i++)
        cin>>arr[i];
    init(n);
    log_init();
    while(q--)  
      {
          long long int l,r;
          cin>>l>>r;
          l--;
          r--;
          cout<<query(l,r)<<"\n";
      }
    return 0;
}