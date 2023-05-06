#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
struct Edge
{
    int to,cost=INF;
};

//adjacency list of the graph
vector<list<Edge>> arr(100,list<Edge>());

//function to add the Edges
//of the graph
void addEdge(int u,int v,int w)
{
    arr[u].push_back({v,w});
    arr[v].push_back({u,w});
}


//function to find the MST
//cost of the graph
int PrimsAlgorithm(int source,int n)
{
   set<pair<int,int>> left;
   set<int> add;
   vector<Edge> mst;
   vector<int> dist(n+1,INT_MAX);
   dist[source]=0;
   for(int i=0;i<n;i++)
         left.insert({dist[i],i});
   int ans=0;

   //iterate till the end of left
   //list
   while (!left.empty())
     {

        int curr= left.begin()->second;
        ans  += dist[curr];
        add.insert(curr);

        //remove the edge from the left
        //list
        left.erase(left.begin());

        //iterate all the adjacent of
        //the current node
        for (auto& edge: arr[curr])
         {
            if (add.count(edge.to) == 1)
                continue; 
            int curr_min = dist[edge.to];
            if (edge.cost < curr_min) {
                left.erase({curr_min, edge.to});
                dist[edge.to] = edge.cost;
                left.insert({dist[edge.to], edge.to});
            }            
        
     }
     }
   return ans;
}
int main()
{
   int n=4;
   int m=5;
 
   addEdge(0,1,5);
   addEdge(1,2,3);
   addEdge(2,0,4);
   addEdge(0,3,2);
   addEdge(3,2,6);
   int source=0;
   int MST=PrimsAlgorithm(source,n);
   cout<<"MST cost\n";
   cout<<MST<<"\n";
   return 0;
}