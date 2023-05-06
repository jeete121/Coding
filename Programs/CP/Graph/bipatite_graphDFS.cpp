#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int src, dest;
};
class Graph
{
public:
	vector<vector<int>> adjList;
	Graph(vector<Edge> const &edges, int N)
	{
		adjList.resize(N);
		for (auto &edge: edges)
		{
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};
bool DFSBipartite(Graph const &graph,int v,vector<bool> &visited,vector<int> &color)
{
    for(int u:graph.adjList[v])
       {
           if(!visited[u])
              {
                  visited[u]=true;
                  color[u]=!color[v];
                  if(!DFSBipartite(graph,u,visited,color))
                     return false;
                  
              }
              else
              {
                if(color[u]==color[v])
                    return false;
              }
              
       }
    return true;
}
int main()
{
	vector<Edge> edges = {
		{1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7},
		{5, 9}, {8, 9}//, {2, 4}
	};
	int N = 10;
	Graph graph(edges, N);
	vector<bool> visited(N,false);
	vector<int> color(N,0);
    visited[0] = true;
    color[0] = 0;
	if(DFSBipartite(graph,1,visited,color))
		cout << "Bipartite Graph";
	else
		cout << "Not a Bipartite Graph";

	return 0;
}