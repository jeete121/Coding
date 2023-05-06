#include <bits/stdc++.h>
using namespace std;
vector<bool> vis;
vector<int> tin,low;
int timer;
vector<int> arr[10001];

//dfs function to find the
//articulation points in the graph
void dfs(int node,int par=-1)
{
   //mark the current node ad visited
    vis[node]=true;

    //assign the in time and low time
    //as cuurent dfs timer
    tin[node]=low[node]=timer;

    //increment the dfs timer
    timer++;
    int children=0;

    //iterate for all adjacent nodes
    //of the current node
    for(int child:arr[node])
      {
          //if node is parent then continue
          if(child==par)
             continue;

         //if already visited
         if(vis[child]==true)
             {
               low[node]=min(low[node],tin[child]);
             }
        else
        {
            dfs(child,node);
            low[node]=min(low[node],low[child]);
            if(low[child]>=tin[node]&&par!=-1)
               cout<<node<<" ";
          children++;
        }
        
      }
    if(par==-1&&children>1)
       cout<<node<<" ";

}
void find_cutpoints(int n)
{
    timer=0;
    vis.assign(n+1,false);
    tin.assign(n+1,-1);
    low.assign(n+1,-1);

}
void addEdge(int u,int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}
int main()
{
    int n=6;
     addEdge(0,1);
     addEdge(0,5);
     addEdge(1,2);
     addEdge(1,3);
     addEdge(2,3);
     addEdge(2,4);
     addEdge(3,4);
     find_cutpoints(n);

     cout<<"Articulation points are: ";
     for(int i=0;i<n;i++)
       {
           if(vis[i]==false)
              dfs(i);
       }
    return 0;
}