#include <bits/stdc++.h>
using namespace std;
const int maxn=10;
vector<int> arr[10001];
int level[10001],LCA[100001][maxn+1];
void dfs(int node,int lvl,int par)
{
    level[node]=lvl;
    LCA[node][0]=par;
    for(int child:arr[node])
       {
             if(child!=par)
               {
                   dfs(child,lvl+1,node);
               }
       }
}
void init(int n)
{
    dfs(1,0,-1);
    for(int i=1;i<=maxn;i++)
      {
          for(int j=1;j<=n;j++)
              {
                  if(LCA[j][i-1]!=-1)
                    {
                        int par=LCA[j][i-1];
                        LCA[j][i]=LCA[par][i];
                    }
              }
      }
}
int getLCA(int a,int b)
{
    if(level[b]<level[a])
       swap(a,b);
    int d=level[b]-level[a];
    while(d>0)
      {
          int i=log2(d);
          b=LCA[b][i];
          d-=1<<i;
      }
    if(a==b)
       return a;
    for(int i=maxn;i>=0;i--)
      {
          if(LCA[a][i]!=-1&&LCA[a][i]!=LCA[b][i])
            {
                a=LCA[a][i];
                b=LCA[b][i];
            }
      }
    return LCA[a][0];
}
int getdist(int a,int b)
{
    int lca=getLCA(a,b);
    return level[a]+level[b]-2*level[lca];
}
int main()
{
    int n,a,b,q;
    cin>>n;
    for(int i=1;i<=n;i++)  
      {
          for(int j=0;j<=maxn;j++)
            {
                LCA[i][j]=-1;
            }
      }
    for(int i=1;i<n;i++)
      {
          cin>>a>>b;
          arr[a].push_back(b);
          arr[b].push_back(a);
      }
      init(n);
      cin>>q;
      while(q--)
        {
            cin>>a>>b;
            cout<<getdist(a,b)<<"\n";
        }
    return 0;
}