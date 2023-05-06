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
struct Node
{
  int v,parent;
};
bool CycleGraph(Graph const &graph,int source,int N)
{
    vector<bool> visited(N,false);
    queue<Node> q;
    q.push({source,-1});
    visited[source]=true;
    while(!q.empty())
     {
        Node node=q.front();
        q.pop();
        for(int u:graph.adjList[node.v])
          {
            if(!visited[u])
              {
                  visited[u]=true;
                  q.push({u,node.v});
              }
              else if(u!=node.parent)
              {
                  return true;
              }
              
          }
     }
    return false;
}
int main()
{
	vector<Edge> edges =
	{
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}, {6, 10}
	};

	int N = 13;
	Graph graph(edges, N);
	if (CycleGraph(graph, 1, N))
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain any cycle";

	return 0;
}