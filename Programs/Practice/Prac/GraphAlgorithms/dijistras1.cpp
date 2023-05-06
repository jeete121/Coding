#include <bits/stdc++.h>
using namespace std;

//pair of adjacency list
vector<pair<int,int>> arr[1001];

//function to add the edges
//into the graph
void addEdge(int u,int v,int w)
{
    //undirected graph with weight
    arr[u].push_back({v,w});
    arr[v].push_back({u,w});
}

//dijistras algorithm for sinle source 
//shortes path
vector<int> dijistraAlgorithm(int n,int source)
{
    //proirity queue to store the minimum
    //distance node first into the queue
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   
   //vector to store the distance
   //of all nodes initialize with INT_MAX(infinite)
    vector<int> dist(n+1,INT_MAX);
   
    //push the source into the queue with distance
    //0
    pq.push({0,source});
  
    //distance of source is 0
    dist[source]=0;

    //iterate till the end of the
    //queue
    while (!pq.empty())
    {
        //current node from the queue
        int curr=pq.top().second;

         //diatance of current node
        int curr_d=pq.top().first;

        //popped out the current node
        //from the queue
        pq.pop();

        //iterate for all adjacent nodes
        //of the current node
        for(pair<int,int> edge:arr[curr])
         {
             //if theie is any update in
             //distance of other nodes
             //then update them
             if(curr_d+edge.second<dist[edge.first])
              {
                  //if the previous distance is
                  //greater then update the new diatance
                  dist[edge.first]=curr_d+edge.second;

                  //push the node into the queue with the
                  //new distance
                  pq.push({dist[edge.first],edge.first});
              }
         }
    }
 //return the distance vector
 //which holds the diatnce of all
 //the nodes
   return dist;
}
int main()
{
     int n=6;

     //make the graph
     //{edge u--v with weight w}
     addEdge(1,2,10);
     addEdge(2,3,5);
     addEdge(1,3,35);
     addEdge(1,6,50);
     addEdge(2,6,10);
     addEdge(3,4,25);
     addEdge(3,5,5);
     addEdge(4,5,6);

     //souece node 
     int source=1;

     vector<int> distance=dijistraAlgorithm(n,source);
     for(int i=1;i<=n;i++)
       {
           //if the node is not reachable from
           //sourece node then print inf
           if(distance[i]==INT_MAX)
              cout<<"Inf ";
        //else  print the distance
           else
             cout<<distance[i]<<" ";
           
       }
    return 0;
}
//Time Complexity: O(nlog(n)+mlog(n))