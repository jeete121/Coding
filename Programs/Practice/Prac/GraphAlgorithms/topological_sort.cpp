#include <bits/stdc++.h>
using namespace std;

//ajdacency list to
//store all the edges
vector<int> arr[100001];

//store the indegree of
//all the nodes
int indegre[100001];
//function to add the edge

void addEdge(int u, int v)
{
  //directed graph
  arr[u].push_back(v);
  //increment the indegee
  indegre[v]++;
}
//funtion to find the topological
//sort of the graph
vector<int> topologicalSort(int n)
{
  //queue to store the nodes
  //of the graph
  queue<int> q;
  //store the result
  vector<int> res;
  //if indegre of the vertex is
  //zero  then insert into the
  //queue
  for (int i = 1; i <= n; i++)
  {
    if (indegre[i] == 0)
    {
      q.push(i);
    }
  }
  //iterate till the queue is
  //not empty
  while (!q.empty())
  {
    //current node from the queue
    int curr = q.front();
    //insert the current data into
    //the result
    res.push_back(curr);
    //popped from the queue
    q.pop();
    //iterate for all the adjacency
    //of the cuurent node
    for (int node : arr[curr])
    {
      //decrease the indegre of the node
      indegre[node]--;
      //if indegree becomes zero
      //add into the queue
      if (indegre[node] == 0)
        q.push(node);
    }
  }
  //return the topological sort
  return res;
}
int main()
{
  int n = 6;
  int edges = 5;
  addEdge(1, 2);
  addEdge(2, 3);
  addEdge(4, 3);
  addEdge(5, 3);
  addEdge(6, 2);
  vector<int> topo = topologicalSort(n);
  cout << "Topological Sort is ";
  for (int i = 0; i < n; i++)
    cout << topo[i] << " ";
  return 0;
}