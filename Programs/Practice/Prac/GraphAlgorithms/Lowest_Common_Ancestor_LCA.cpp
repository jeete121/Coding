#include  <bits/stdc++.h>
using namespace std;
vector<int> arr[1000001];
vector<int> tree;
vector<int> height,euler,first;
vector<bool> vis;
int n;
void dfs(int node,int h=0)
{
    vis[node]=true;
    height[node]=h;
    first[node]=euler.size();
    euler.push_back(node);
    for(int child:arr[node])
      {
          if(vis[child]==0)
            {
                dfs(child,h+1);
                euler.push_back(node);
            }
      }
}
void build(int node,int start,int end)
{
    if(start==end)
       tree[node]=euler[start];
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        int l=tree[2*node];
        int r=tree[2*node+1];
        if(height[l]<height[r])
           tree[node]=l;
        else
          tree[node]=r;
    }
}
void LCA(int root) 
{
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        vis.assign(n+1, false);
        dfs(root);
        int m = euler.size();
        tree.resize(m * 4);
        build(1, 0, m - 1);
}
int query(int node,int start,int end,int l,int r)
{
    if(r<start||l>end)
       return -1;
    if(l<=start&&r>=end)
       return tree[node];
    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node+1,mid+1,end,l,r);
    if(p1==-1)
       return p2;
    if(p2==-1)
       return p1;
    if(height[p1]<height[p2])
       return p1;
    else 
       return p2;
}

int lca(int u,int v)
{
    int left=first[u],right=first[v];
    if(left>right)
       swap(left,right);
    return query(1,0,euler.size()-1,left,right);
}

int main()
{  
 int m;
  cin>>n>>m;
  while(m--)
    {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    LCA(1);
    int q;
    cin>>q;
    while(q--)
     {
         int u,v;
         cin>>u>>v;
         cout<<lca(u,v)<<"\n";
     }
  return 0;
}