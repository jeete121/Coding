#include <bits/stdc++.h>
using namespace std;
vector<int> arr[1000001];
int MAXN=25;
const int N=200010;
int LCA[N][25];
int level[N];
int n;
void dfs(int node,int par,int l)
{
    LCA[node][0]=par;
    level[node]=l;
    for(int child:arr[node])
      {
          if(child!=par)
              dfs(child,node,l+1);
      }
}
void init()
{
    dfs(1,-1,0);
    for(int j=1;j<=MAXN;j++)
      {
             for(int i=1;i<=n;i++)
               {
                   if(LCA[i][j-1]!=-1)
                   {
                   int par=LCA[i][j-1];
                      LCA[i][j]=LCA[par][j-1];
                   }
               }
      }
}
int get_ans(int a,int b)
{
    if(level[a]>level[b])
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
    while(LCA[a][0]!=LCA[b][0]) 
      {
          a=LCA[a][0];
          b=LCA[b][0];
      }
    return LCA[a][0];
    
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n-1;i++)
      {
          int a,b;
          cin>>a>>b;
          arr[a].push_back(b);
          arr[b].push_back(a);
      }
      memset(LCA,-1,sizeof(LCA));
      init();
      int q;
      cin>>q;
      //cout<<N<<"\n";
      while(q--)
        {
            int r,u,v;
            cin>>r>>u>>v;
            int a=get_ans(u,v);
            int b=get_ans(r,u);
            int c=get_ans(r,v);
            if(a==b)
               cout<<c<<"\n";
            else if(b==c)
               cout<<a<<"\n";
            else
              cout<<b<<"\n";
        }
}