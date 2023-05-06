#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
vector<long long> arr[1000001];
long long vis[1000001];
long long size;
void dfs(long long v)
{
   vis[v]=1;
   size++;
   for(long long child:arr[v])
    {
        if(vis[child]==0)
          {
              dfs(child);
          }
    }
}
int main()
{
    long long t,n,m;
    cin>>t;
    while(t--)
      {
          cin>>n>>m;
          for(long long i=0;i<=n;i++)
             vis[i]=0;
          for(long long i=0;i<=n;i++)
              arr[i].clear();
          while(m--)
            {
                long long a,b;
                cin>>a>>b;
                arr[a].push_back(b);
                arr[b].push_back(a);
            }
            long long cnt=0;
            long long ans=1;
            for(long long i=1;i<=n;i++)
               {
                   if(vis[i]==0)
                     {
                         size=0;
                         dfs(i);
                         cnt++;
                         ans=(ans*size)%MOD;
                     }
               }
            cout<<cnt<<" "<<ans<<"\n";
      }
}