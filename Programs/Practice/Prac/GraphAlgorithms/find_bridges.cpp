#include <bits/stdc++.h>
using namespace std;

//adjacency list of the graph
vector<int> arr[10001];
int vis[10001],in[10001],low[10001];
int timer;
int cnt;
void dfs(int node,int par)
{
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;
    for(int child:arr[node])
    {
        if(child==par)
           continue;
       if(vis[child]==1)
          {
              //edge node-child is a back edge
              low[node]=min(low[node],in[child]);
          }
        else
        {
         //edge node-child is a forward edge
         dfs(child,node);
         if(low[child]>in[node])
              {
                  cnt++;
                  cout<<node<<" - "<<child<<" is a bridge\n";
              }
            low[node]=min(low[child],low[node]);
        }
        
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
      {
          int a,b;
          cin>>a>>b;
          arr[a].push_back(b);
          arr[b].push_back(a);
      }
    dfs(1,-1);
    cout<<cnt<<"\n";
    return  0;
}