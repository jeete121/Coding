#include <bits/stdc++.h>
using namespace std;

//adjacency list of the graph
vector<int> arr[10001];
//visited array,in array,low array
int visited[10001],in[10001],low[10001];

//varible for dfs timer
int timer;

//variable for counter
int cnt;

//function to add the edges into
//the graph
void addEdge(int u,int v)
{
    //graph is undirected
    arr[u].push_back(v);
    arr[v].push_back(u);
}
//dfs function
void dfs(int node,int par)
{
    //mark the current node as visited
    visited[node]=1;

    //in time and low time as current timer value
    in[node]=low[node]=timer;

    //increment the timer for next time
    timer++;

    //now interate for all adjacent nodes of the
    //current nodes
    for(int child:arr[node])
    {
      //if child is same parent then
      //continue
       if(child==par)
           continue;
      //if alredy visited
       if(visited[child]==1)
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
    int n=6;
    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,1);
    addEdge(4,3);
    addEdge(5,4);
    addEdge(6,4);
    addEdge(5,6);
    dfs(1,-1);
    cout<<"Number of brides are ";
    cout<<cnt<<"\n";
    return  0;
}