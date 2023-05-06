#include <bits/stdc++.h>
using namespace std;
#define INF 9999999

//function to find the all pair shortest
//path 
void floyedWarshall(int dist[][6],int n)
{
   for(int k=0;k<n;k++)
      {
        for(int i=0;i<n;i++)
           {
            for(int j=0;j<n;j++)
                {
                 if(dist[i][k]<INF &&dist[k][j]<INF)
                   {

                     //update distance of the node
                     //as min of previous and after include that vertex
                     //as intermediate      
                     dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
     }
}
int main()
{
    int n=6;
    int dist[6][6];
    //all edges in the graph 
    //graph is undirected
     vector<vector<int>> edges={{1,2,10},{2,1,10},{2,3,5},
                             {3,2,5},{1,3,35},{3,1,35},
                             {1,6,50},{6,1,50},{6,2,10},
                             {4,3,25},{5,3,5},{5,4,6},
                             {2,6,10},{3,4,25},{3,5,5},
                             {4,5,6}};
   //initailize all the distance as infinite
   // and self as 0
    for(int i=0;i<n;i++)
     {
       for(int j=0;j<n;j++)
         {
             if(i!=j)
                dist[i][j]=INF;
             else
               dist[i][j]=0;
         }    
     }
     for(int i=0;i<edges.size();i++)
       {
           int a=edges[i][0];
           int b=edges[i][1];
           int w=edges[i][2];
          //covert the vertex from 0 to n-1
           a--;
           b--;

           //add edge with weight into
           //the dist array
           dist[a][b]=w;
           dist[b][a]=w;
       }
  //call the floyed warshall algorithm
   floyedWarshall(dist,n);

 //print the distance for
 //all pair shortest paths
  for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
             {
                 if(dist[i][j]==INF)
                    cout<<"INF ";
                 else
                    cout<<dist[i][j]<<" ";
                 
             }
         cout<<"\n";
     }
    return 0;
}
