#include <bits/stdc++.h>
using namespace std;

//adjacency list of the graph and
//the transpose of the graph
vector<int> arr[10001],tr[10001];

//vector order and SCC
vector<int> order,SCC;

//visited array to hold
//the which are  visited 
int vis[10001];

//function of the dfs
void dfs(int node)
{
    //marks current node as visted
    vis[node]=1;

    //iterate for the adjacent  of the
    //current node
    for(int child:arr[node])
     {
         //if child is not visited
         //call dfs for child
         if(vis[child]==0)
             dfs(child);
     }
     
    //store the order 
    order.push_back(node);
}

//funuction of dfs
void dfs1(int node)
{

    //mark the current node as 
    //visited
    vis[node]=1;

    //iterate for the adjacent 
    //of the current node
    for(int child:tr[node])
     {
         //if child is not visited 
         //call dfs for it
         if(vis[child]==0)
            dfs1(child);
     }

    //store the SCC
    SCC.push_back(node);
}
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
          {
              vis[i]=0;
              arr[i].clear();
              tr[i].clear();
              order.clear();
          }
          while(m--)
           {
               int a,b;
               cin>>a>>b;
               arr[a].push_back(b);
               tr[b].push_back(a);
           }
         for(int i=1;i<=n;i++)
          {
              if(vis[i]==0)
                 dfs(i);
          }
        for(int i=1;i<=n;i++)
           vis[i]=0;
        for(int i=1;i<=n;i++)
         {
             if(vis[order[n-i]]==0)
               {
                   SCC.clear();
                   dfs1(order[n-i]);
                   cout<<"dfs1() call from "<<order[n-i]<<" SCC is\n";
                   for(int node:SCC)
                       cout<<node<<" ";
                cout<<"\n";
               }
         }
    }
}