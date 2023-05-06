/*
 Single Source Sortest path
 Time:O(V*E)
*/
#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int source,dest,weight;
};
void printPath(vector<int> const &parent, int v)
{
	if (v < 0)
		return;
	printPath(parent, parent[v]);
	cout<<v <<" ";
}
void BellmanFord(vector<Edge> const &edges,int source,int N)
{
    int E=edges.size();
    vector<int> dist(N,INT_MAX);
    dist[source]=0;
    vector<int> parent(N,-1);
    int u,v,w;
    for(int i=0;i<N-1;i++)
     {
         for(int j=0;j<E;j++)
          {
              u=edges[j].source;
              v=edges[j].dest;
              w=edges[j].weight;
              if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
               {
                   dist[v]=dist[u]+w;
                   parent[v]=u;
               }
          }
     }
     for(int i=0;i<N;i++)
       {
           u=edges[i].source;
           v=edges[i].dest;
           w=edges[i].weight;
           if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
             {
                 cout<<"Graph contains Negative cycle\n";
                 return;
             }
       }
	for (int i = 0; i < N; i++)
	{
		cout << "Distance of vertex " << i << " from the source is "
			 << setw(2) << dist[i] << ". It's path is [ ";
		printPath(parent, i); cout << "]" << '\n';
	}
}
int main()
{
	vector<Edge> edges =
	{
		{ 0, 1, -1 }, { 0, 2, 4 }, { 1, 2, 3 }, { 1, 3, 2 },
		{ 1, 4, 2 }, { 3, 2, 5 }, { 3, 1, 1 }, { 4, 3, -3 }
	};
	int N = 5;
	int source = 0;
	BellmanFord(edges, source, N);
	return 0;
}