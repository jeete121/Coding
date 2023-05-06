/*
Time : O(N)
Space: O(N) 
*/
#include <bits/stdc++.h>
using namespace std;
// struct Tree
// {
//     int data;
//     Tree *left;
//     Tree *right;
// };
int vis[100001];
int level[10001];
vector<int> arr[10001];
int parent[10001];
void bfs(int node,int par)
{
    queue<int> q;
    q.push(node);
    vis[node]=1;
    parent[node]=par;
    level[node]=0;
    while(!q.empty())
     {
         int curr=q.front();
         q.pop();
         for(int child:arr[curr])
           {
               if(vis[child]==0)
                 {
                     vis[child]=1;
                     level[child]=level[curr]+1;
                     parent[child]=curr;
                     q.push(child);
                 }
           }
     }

}
int LCA(int a,int b)
{
    if(level[a]>level[b])
      swap(a,b);
    int d=level[b]-level[a];
    while(d>0)
     {
         b=parent[b];
         d--;
     }
    if(a==b)
       return a;
    while(parent[a]!=parent[b])
      {
          a=parent[a];
          b=parent[b];
      }
    return parent[a];
}
int main()
{
    int  n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
      {
          int a,b;
          cin>>a>>b;
          arr[a].push_back(b);
      }
      bfs(1,-1);
    //   for(int i=1;i<=n;i++)
    //      {
    //          cout<<parent[i]<<" ";
    //      }
    int a,b;
    cin>>a>>b;
    cout<<LCA(a,b);
         return 0;

}