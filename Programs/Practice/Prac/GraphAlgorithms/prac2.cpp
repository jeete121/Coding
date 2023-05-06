#include <bits/stdc++.h>
using namespace std;

//pair of adjacency list
vector<pair<int,int>> arr[100001];
//function to add the edges
//into the graph
void addEdge(int u,int v,int w)
{
    //undirected graph with weight
    arr[u].push_back({v,w});
    arr[v].push_back({u,w});
}
int vis[100001];
int dist[100001];
int minimum[100001];
int max1[100001];
void bfs(int s)
{
   queue<int> q;
   q.push(s);
   dist[s]=0;
   vis[s]=1;
   while(!q.empty())
    {
       s=q.front();
       q.pop();
       for(auto it: arr[s])
         {
            if(vis[it.first]==0)
              {
                 vis[it.first]=1;
                 dist[it.first]=dist[s]+it.second;
                 minimum[it.first]=min(minimum[it.first],it.second);
                 max1[it.first]=max(max1[it.first],it.second);
                 q.push(it.first);
              }
         }
    }
}
int main()
{
     int n,m;
     cin>>n>>m;
     while(m--)
     {
        int a,b,w;
        cin>>a>>b>>w;
        addEdge(a,b,w);
     } 
     int source=1;
     for(int i=2;i<=n;i++)
       minimum[i]=INT_MAX;
     for(int i=2;i<=n;i++)
        max1[i]=INT_MIN;
   
     for(int i=2;i<=n;i++)
        cout<<minimum[i]<<" ";
      cout<<"\n";
     bfs(source);
     
     for(int i=2;i<=n;i++)
        cout<<dist[i]<<" ";
     cout<<"\n";
     for(int i=2;i<=n;i++)
        cout<<max1[i]<<" ";
      cout<<"\n";
     for(int i=2;i<=n;i++)
        cout<<minimum[i]<<" ";
      cout<<"\n";
     for(int i=2;i<=n;i++)
       {
        
             cout<<dist[i]-max1[i]+minimum[i]<<" ";
       }
    return 0;
}