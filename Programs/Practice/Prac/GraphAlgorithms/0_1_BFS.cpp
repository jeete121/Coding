#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> arr[101];

//function to add edges into
//the graph
void addEdge(int u,int v,int w)
{
    arr[u].push_back({v,w});
    arr[v].push_back({u,w});
}

//function for 0-1 BFS
void BFS(int n,int source,vector<int> &dist)
{

  //dist of source as 1
   dist[source]=0;

   //take a deque
   deque<int> q;

   //push the source at front
   //of queue
   q.push_front(source);

   //iterate till the queue is not
   //empty
   while(!q.empty())
     {
         int v=q.front();

         //pop the front element from
         //queue
         q.pop_front();

         //iterate for all adjacent nodes of
         //the current node
         for(auto edge:arr[v])
           {
               int u=edge.first;
               int w=edge.second;

               //update  weight for
               //the new node
               if(dist[v]+w<dist[u])
                 {
                     dist[u]=dist[v]+w;

                     //if weight is 1 then push
                     //it at back of queue
                     if(w==1)
                       q.push_back(u);

                    //else push it at front of
                    //queue
                      else
                       q.push_front(u);
                      
                 }
           }
     }
}
int main()
{
    int n=5;
    addEdge(1,2,1);
    addEdge(1,3,0);
    addEdge(2,4,0);
    addEdge(3,4,1);
    addEdge(4,5,1);
    addEdge(2,5,1);

    vector<int> dist(n+1,INT_MAX);
    int source=1;
    BFS(n,source,dist);
    for(int i=1;i<=n;i++)
      cout<<dist[i]<<" ";
    return 0;
}