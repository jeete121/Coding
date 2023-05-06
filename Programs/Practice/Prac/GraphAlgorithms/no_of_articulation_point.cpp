#include <bits/stdc++.h>
using namespace std;
vector<int> arr[100001];
int vis[100001];
int in[100001],low[100001];
int timer;
set<int> st;
void dfs(int node,int par=-1)
{
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;
    int children=0;
    for(int child:arr[node])
     {
         if(child==par)
            continue;
        if(vis[child]==1)
          {
              low[node]=min(low[node],in[child]);
          }
         else
         {
             dfs(child,node);
             low[node]=min(low[node],low[child]);
             if(low[child]>=in[node]&&par!=-1)
                {
                    st.insert(node);
                }
            children++;
         }
         
     }
    if(par==-1&&children>1)
       st.insert(node);
}
int main()
{
    int n,m;
    while(cin>>n)
    {
        cin>>m;
      if(n==0&&m==0)
         break;
      else
      {
        st.clear();
       for(int i=1;i<=n;i++)
        {
            vis[i]=0;
            in[i]=0;
            low[i]=0;
            arr[i].clear();
        }
    while(m--)
      {
          int a,b;
          cin>>a>>b;
          arr[a].push_back(b);
          arr[b].push_back(a);
      }
 
      
        dfs(1);
      cout<<st.size()<<"\n";
      }
    }


    return 0;
}