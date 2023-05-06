#include <bits/stdc++.h>
using namespace std;
//adjacency list
vector<int> adj[1001];
//visited array to hold
//which node is visit and which
//is not
bool visited[100001];
//function to add the edge
//into the adjacency list
void addEdge(int u,int v)
{
    //undirected graph
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//function to find DFS traversal of
//a graph
void dfsTraversal(int node)
{
    //mark the current node as
    //visited
    visited[node]=1;
    //print the current node
    cout<<node<<" ";
    //iterate through adjacency list
    //of the current node
    for(int child:adj[node])
     {
         //if node visited then call the 
         //dfs for it
         if(visited[child]==0)
           {
               dfsTraversal(child);
           }
     }
}
int main()
{
  int n=8;
  int edges=5;
  addEdge(1,2);
  addEdge(1,3);
  addEdge(4,5);
  addEdge(4,6);
  addEdge(7,8);
  cout<<"Connected componets are\n";
  for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
          {
              dfsTraversal(i);
              cout<<"\n";
          }
          
    }
   return 0;
}