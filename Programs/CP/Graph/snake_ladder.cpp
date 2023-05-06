#include <bits/stdc++.h>
using namespace std;
#define N 100
struct Edge
{
	int src, dest;
};
class Graph
{
public:
	vector<int> adjList[N+1];
	Graph(vector<Edge> const &edges)
	{
		for(int i=0;i<edges.size();i++)
           {
             int src=edges[i].src;
             int dest=edges[i].dest;
             adjList[src].push_back(dest);
           }
	}
};
struct Node
{
  int ver;
  int minDist;
};
void BFS(Graph const &graph,int source)
{
  queue<Node> q;   
  vector<bool> visited(N+1,false);
  visited[source]=true;
  Node node={source,0};
  q.push(node);
  while(!q.empty())
    {
        node=q.front();
        q.pop();
        if(node.ver==N)
          {
              cout<<node.minDist<<" ";
              break;
          }
         for(int u:graph.adjList[node.ver])
             {
                 if(!visited[u])
                   {
                       visited[u]=true;
                       Node n={u,node.minDist+1};
                       q.push(n);
                   }
             }

    }

}
void findSolution(unordered_map<int,int> &ladder,unordered_map<int,int> &snake)
{
  vector<Edge> edges;
  for(int i=0;i<N;i++)
     {
       for(int j=1;j<=6&&i+j<=N;j++)
          {
            int src=i;
            int dest=(ladder[i+j]||snake[i+j])?(ladder[i+j]+snake[i+j]):(i+j);
            Edge e={src,dest};
            edges.push_back(e);
          }
     }
    Graph g(edges);
   BFS(g,0);
}
int main()
{
  unordered_map<int,int> snake,ladder;
 ladder[1] = 38;
	ladder[4] = 14;
	ladder[9] = 31;
	ladder[21] = 42;
	ladder[28] = 84;
	ladder[51] = 67;
	ladder[72] = 91;
	ladder[80] = 99;

	snake[17] = 7;
	snake[54] = 34;
	snake[62] = 19;
	snake[64] = 60;
	snake[87] = 36;
	snake[93] = 73;
	snake[95] = 75;
	snake[98] = 79;
   findSolution(ladder,snake);
   return 0;
}