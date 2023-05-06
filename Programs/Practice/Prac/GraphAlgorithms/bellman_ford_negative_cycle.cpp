#include <bits/stdc++.h>
using namespace std;
#define INF 10000000000
struct  Edge
{
    long long a,b,w;
};
vector<Edge> arr;
long long max1(long long a,long long b)
{
  if(a>b)
    return a;
   return b;
}
int main()
{
    long long n,m;
    cin>>n>>m;
    arr.resize(1000001);
    for(long long i=0;i<m;i++)
    {
        long long x,y,w;
        cin>>x>>y>>w;
        arr[i].a=x;
        arr[i].b=y;
        arr[i].w=w;
    }
    vector<long long> dist(n,INF);
    vector<long long> parent(n,-1);
    dist[1]=0;
    long long x=1;
    for(long long i=0;i<n;i++)
      {
          x=-1;
          for(long long j=0;j<m;j++)
            {
                if(dist[arr[j].a]<INF)
                  {
                      if(dist[arr[j].b]>dist[arr[j].a]+arr[j].w)
                        {
                            dist[arr[j].b]=max1(-INF,dist[arr[j].a]+arr[j].w);
                            parent[arr[j].b]=arr[j].a;
                            x=arr[j].b;
                        }
                  }
            }
      }
      //cout<<x<<"\n";
      if(x==-1)
         cout<<"NO\n";
      else
      {
         long long y=x;
         for(long long i=0;i<n;i++)
            y=parent[y];
         vector<long long> path;
         for(long long curr=y;;curr=parent[curr])
           {
               path.push_back(curr);
               if(curr==y&&path.size()>1)
                  break;
           }
           cout<<"YES\n";
           for(long long i=path.size()-1;i>=0;i--)
              cout<<path[i]<<" ";
            cout<<"\n";
      }
      
    
}