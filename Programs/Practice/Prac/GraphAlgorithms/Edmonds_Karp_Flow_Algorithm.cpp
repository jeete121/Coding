#include <bits/stdc++.h>
using namespace std;
vector<long long int> arr[1000001];
long long int capacity[1001][1001];
const long long int INF=100000000000000000;
long long int n;
long long int  bfs(long long int src,long long int dest,vector<long long int> &parent)
{
    fill(parent.begin(),parent.end(),-1);
    parent[src]=-2;
    queue<pair<long long int,long long int>> q;
    q.push({src,INF});
    while(!q.empty())
     {
         long long int curr=q.front().first;
         long long int flow=q.front().second;
         q.pop();
         for(long long int child:arr[curr])
           {
               if(parent[child]==-1&&capacity[curr][child])
                   {
                       parent[child]=curr;
                       long long int new_flow=min(flow,capacity[curr][child]);
                       if(child==dest)
                          return new_flow;
                       q.push({child,new_flow});
                   }
           }
     }
     return 0;
}
long long int max_flow(long long int src,long long int dest)
{
    long long int flow=0;
    vector<long long int> parent(n+1);
    long long int new_flow;
    while(new_flow=bfs(src,dest,parent))
      {
          flow+=new_flow;
          long long int curr=dest;
          //cout<<"ajjja\n";
          //cout<<new_flow<<"\n";
          while(curr!=src)
            {
                long long int prev=parent[curr];
                capacity[prev][curr]-=new_flow;
                capacity[curr][prev]+=new_flow;
                curr=prev;
            }
      }
      
    return flow;
}
 int main()
{
   long long int m;
   cin>>n>>m;
  // capacity.resize(n);
   while(m--)
    {
        long long int a,b,w;
        cin>>a>>b>>w;
        arr[a].push_back(b);
        arr[b].push_back(a);
        //capacity[a].push_back(w);
        //capacity[b].push_back(w);
        capacity[a][b]+=w;
        capacity[b][a]+=w;
    }
     long long int ans=max_flow(1,n);
    cout<<ans<<"\n";
    return 0;
}