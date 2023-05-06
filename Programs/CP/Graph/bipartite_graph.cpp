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
bool BipartiteGraph(Graph const &graph,int v,int N )
{
    queue<int> q;
    vector<bool> visited(N,false);
    vector<int> level(N);
    q.push(v);
    visited[v]=true;
    level[v]=0;
    while(!q.empty())
      {
         v=q.front();
         q.pop();
         for(int u:graph.adjList[v])
           {
               if(!visited[u])
                 {
                     visited[u]=true;
                     q.push(u);
                     level[u]=level[v]+1;
                 }
                 else
                 {
                   if(level[v]==level[u])
                      return false;
                 }
                 
           }
      }
    return true;
}
int main()
{
	vector<Edge> edges = {
		{1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7},
		{5, 9}, {8, 9},{1,3}
	};
	int N = 11;
	Graph graph(edges, N);
	if (BipartiteGraph(graph, 1, N))
		cout << "Bipartite Graph";
	else
		cout << "Not a Bipartite Graph";
	
	return 0;
}