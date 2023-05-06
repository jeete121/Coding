#include <bits/stdc++.h>
using namespace std;
const long long int N=100005;
long long int MAXN=17;
long long int LCA[N][17];
long long int level[N];
long long int n;
long long int max1[N][17];
long long int min1[N][17];
long long int sum[N][17];
vector<pair<long long int,long long int>> arr[N];
long long int maxans,minans;
void dfs(long long int node,long long int par,long long int l,long long int dist)
{
   level[node]=l;
   LCA[node][0]=par;
   min1[node][0]=dist;
   max1[node][0]=dist;
   sum[node][0]=dist;
   for(pair<long long int,long long int> child:arr[node])
     {
         if(child.first!=par)
           dfs(child.first,node,l+1,child.second);
     }
}
void init()
{
   dfs(1,-1,0,0);
   for(long long int j=1;j<=MAXN;j++)
     {
        for(long long int i=1;i<=n;i++)
          {
             if(LCA[i][j-1]!=-1)
               {
                  long long int par=LCA[i][j-1];
                  LCA[i][j]=LCA[par][j-1];
                  sum[i][j]+=sum[par][j-1]+sum[i][j-1];
                  max1[i][j]=max(max1[i][j-1],max1[par][j-1]);
                  min1[i][j]=min(min1[i][j-1],min1[par][j-1]);
               }
          }
     }
}
int  get_ans(long long int a,long long int b)
{
   if(level[a]>level[b])
      swap(a,b);
   long long int d=level[b]-level[a];
   maxans=-( 1e9 ),minans=( 1e9 );
   long long int ans=0;
   while(d>0)
   {
      long long int i=log2(d);
      ans+=sum[b][i];
      minans=min(minans,min1[b][i]);
      maxans=max(maxans,max1[b][i]);
      b=LCA[b][i];
      d-=1<<i;
   }
   if(a==b)
      return ans;
   while(LCA[a][0]!=LCA[b][0])
     {
        ans+=LCA[a][0];
        ans+=LCA[b][0];
        minans=min(minans,min(min1[b][0],min1[a][0]));
        maxans=max(maxans,max(max1[a][0],max1[b][0]));
        a=LCA[a][0];
        b=LCA[b][0];
     }
   ans+=LCA[b][0];
   ans+=LCA[a][0];
    minans=min(minans,min(min1[b][0],min1[a][0]));
    maxans=max(maxans,max(max1[a][0],max1[b][0]));
    return ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
      int q,r;
   cin>>n;
   cin>>q>>r;
   for(long long int i=1;i<=n-1;i++)
     {
        long long int a,b,w;
        cin>>a>>b>>w;
        arr[a].push_back({b,w});
        arr[b].push_back({a,w});
     }
     memset(LCA,-1,sizeof(LCA));
     memset(max1,-(1e9),sizeof(max1));
     memset(min1,(1e9),sizeof(min1));
     memset(sum,0,sizeof(sum));
     init();
     while(q--)
     {
        long long int u,v;
        cin>>u>>v;
        int b=get_ans(r,u);
        int c=get_ans(r,v);
        cout<<b+c<<"\n";
     }
   }
   return 0;
}