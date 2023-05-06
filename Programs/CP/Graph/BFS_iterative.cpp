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
void BFS(Graph const &graph,int v,vector<bool> &visited)
{
   queue<int> q;
   q.push(v);
   visited[v]=true;
   while(!q.empty())
    {
		 v=q.front();
		q.pop();
		cout<<v<<" ";
		for(int u:graph.adjList[v])
		  {
			  if(!visited[u])
			    {
					visited[u]=true;
					q.push(u);
				}
		  }
	}
}
int main()
{
	vector<Edge> edges = {
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
	};
	int N = 15;
	Graph graph(edges, N);
	vector<bool> visited(N, false);
	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			BFS(graph, i, visited);
		}
	}

	return 0;
}