#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int source,dest,weight;
};
unordered_map<int,int> parent;
void makeSet(int N)
{
    for(int i=0;i<N;i++)
      parent[i]=i;
}
int Find(int k)
{
    if(parent[k]==k)
      return k;
    return 
       Find(parent[k]);
}
void Union(int a,int b)
{
  a=Find(a);
  b=Find(b);
  if(a==b)
     return;
  parent[a]=b; 
}
vector<Edge> KrushkalsAlgo(vector<Edge> &edges,int N)
{
    vector<Edge> MST;
    makeSet(N);
    while(MST.size()!=N-1)
      {
          Edge next_edge=edges.back();
          edges.pop_back();
          int x=Find(next_edge.source);
          int y=Find(next_edge.dest);
          if(x!=y)
           {
            MST.push_back(next_edge);
            Union(x,y);
           }
      }
     return MST;
}
struct compare
{
	inline bool operator() (Edge const &a, Edge const &b)
	{
		return (a.weight > b.weight);
	}
};
int main()
{
	vector<Edge> edges =
	{
		{ 0, 1, 7 }, { 1, 2, 8 }, { 0, 3, 5 }, { 1, 3, 9 },
		{ 1, 4, 7 }, { 2, 4, 5 }, { 3, 4, 15 }, { 3, 5, 6 },
		{ 4, 5, 8 }, { 4, 6, 9 }, { 5, 6, 11 }
	};
	sort(edges.begin(), edges.end(), compare());
	int N = 7;
	vector<Edge> e = KrushkalsAlgo(edges, N);
   int res=0;
	for (Edge &edge: e)
		{
            cout << "(" << edge.source << ", " << edge.dest << ", "
			<< edge.weight << ")" << endl;
         res+=edge.weight;
        }
    cout<<res<<"\n";   
 	return 0;
}