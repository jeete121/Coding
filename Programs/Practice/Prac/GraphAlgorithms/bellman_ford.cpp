#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
//structure for the Edges of
//the graph
struct Edge
{
    int a;
    int b;
    int w;
};

//Edge to store the edges 
//of the graph
Edge arr[1000001];
vector<int> bellmanFord(int n,int m,int source)
{
   //vector to store the distance of
   //all nodes initialize with INF
   vector<int> dist(n+1,INF);

   //vector to store the parent
   //of all nodes initialize with -1
   vector<int> parent(n+1,-1);
   
   //make diatance of source as 0
   dist[source]=0;

   //make parent of source as null
   parent[source]=-1;


   bool flag;

   //iterate for all the nodes
   for(int i=0;i<n-1;i++)
     {
         flag=false;

         //iterate  for all the edges
         for(int j=0;j<m;j++)
            {
                if(dist[arr[j].a]<INF)
                  {
                      //if previous distance is more
                      //then update with new distance
                      if(dist[arr[j].b]>dist[arr[j].a]+arr[j].w)
                         {
                             flag=true;
                            //update the distance
                             dist[arr[j].b]=dist[arr[j].a]+arr[j].w;

                             //make parent as current node
                             parent[arr[j].b]=arr[j].a;
                         }
                  }
            }
        //if their is no update we 
        //break out of loop because in 
        //furthur steps their is also no update
          if(flag==false)
             break;
     }
   return dist;
}
int main()
{
     int n=6;
     //all edges in the graph 
     //graph is undirected
     vector<vector<int>> edges={{1,2,10},{2,1,10},{2,3,5},
                             {3,2,5},{1,3,35},{3,1,35},
                             {1,6,50},{6,1,50},{6,2,10},
                             {4,3,25},{5,3,5},{5,4,6},
                             {2,6,10},{3,4,25},{3,5,5},
                             {4,5,6}};

   //insert all edges into the list
    for(int i=0;i<edges.size();i++)
      {
          arr[i].a=edges[i][0];
          arr[i].b=edges[i][1];
          arr[i].w=edges[i][2];
      }
  //source vertex
  int source=1;

   vector<int> dist=bellmanFord(n,edges.size(),source);

   //print the distance of all nodes

   for(int i=1;i<=n;i++)
     {
         if(dist[i]==INF)
            cout<<"inf ";
         else
           cout<<dist[i]<<" ";
     }
   return 0;
} 