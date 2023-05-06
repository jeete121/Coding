#include <bits/stdc++.h>
using namespace std;


vector<int> arr[100001];
int vis[100001];
int n;
vector<vector<int> > res;


void dfs(int node,vector<int> path)
{

    //mark as visited 
    vis[node]=1;

    //add into the path
    path.push_back(node);

    //if we reach at the destination
     if(node==n-1)
        res.push_back(path);

    //else 
    else
        {

            //iterate for all adjacent nodes of the
            //current node
            for(int child:arr[node])
            {

                //if not visited then call
                //for it
                if(vis[child]==0)
                      dfs(child,path);
            }
        }
     //backtrack
         vis[node]=0;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
{
    n=graph.size();
        for(int i=0;i<graph.size();i++)
        {
            vis[i]=0;
            arr[i].clear();
        }
        for(int i=0;i<graph.size();i++)
        {
            vector<int> v=graph[i];
            for(int j=0;j<v.size();j++)
                arr[i].push_back(v[j]);
        }
        res.clear();
        vector<int> path;
        dfs(0,path);
       return res; 
}

int main()
{
    vector<vector<int>> graph ={{1,2},{3},{3},{}};
    vector<vector<int>> paths=allPathsSourceTarget(graph);
    cout<<"[";
    for(int i=0;i<paths.size();i++)
      {
          cout<<"[";
          for(int j=0;j<paths[i].size();j++)
           {
               cout<<paths[i][j];
               if(j!=paths[i].size()-1)
                 cout<<",";
           }
         cout<<"]";
          if(i!=paths.size()-1)
            cout<<",";
      }
    cout<<"]";

    return 0;
}