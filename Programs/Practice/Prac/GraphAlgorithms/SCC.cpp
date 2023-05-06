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
     int n=6;

     //original graph
     arr[1].push_back(2);
     arr[2].push_back(3);
     arr[3].push_back(1);
     arr[3].push_back(5);
     arr[5].push_back(4);
     arr[4].push_back(6);
     arr[6].push_back(5);

     //transpose graph
     tr[2].push_back(1);
     tr[3].push_back(2);
     tr[1].push_back(3);
     tr[5].push_back(3);
     tr[4].push_back(5);
     tr[6].push_back(4);
     tr[5].push_back(6);


    //run dfs for all the nodes to
    //decide the order
     for(int i=1;i<=n;i++)
        {
              if(vis[i]==0)
                 dfs(i);
        }
    //mark all nodes as unvisited
    //for second dfs
     for(int i=1;i<=n;i++)
         vis[i]=0;
    //now iterate for all
    //nodes
    for(int i=1;i<=n;i++)
         {
             //if vis of that order is unvisited
             if(vis[order[n-i]]==0)
               {
                   //claer SCC for next round
                   SCC.clear();
                   
                   //call the dfs
                   dfs1(order[n-i]);
                   cout<<"SCC from "<<order[n-i]<<" is\n";
                   for(int node:SCC)
                       cout<<node<<" ";
                cout<<"\n";
               }
         }
   return 0;
}