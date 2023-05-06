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
void bfsTraversal(int node)
{
    //queue to hold the nodes
    queue<int> q;
    q.push(node);
    //make visited the current node
    visited[node]=1;
    //iterate till queue is not empty
    while(!q.empty())
      {
          //store the front element from queue
          node=q.front();
          //print the front element of the queue
          cout<<node<<" ";
          //pop out the first element of the queue
          q.pop();
          //iterate through the adjacency list
          //of the popped element
          for(int child:adj[node])
            {
                //if not visited then push into
                //queue and make it as visited
                if(visited[child]==0)
                 {
                     q.push(child);
                     visited[child]=1;
                     
                 }
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
    cout<<"Connected Components are\n";
    for(int i=1;i<=n;i++)
      {
          if(visited[i]==0)
            {
                bfsTraversal(i);
                cout<<"\n";
            }
      }
    return 0;
}
//Time Complexity: O(n+m)
//where n=no of nodes,m=no of edges