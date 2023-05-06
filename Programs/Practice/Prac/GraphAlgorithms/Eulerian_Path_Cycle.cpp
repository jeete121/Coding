#include <bits/stdc++.h>
using namespace  std;
vector<vector<int>> g(10001, vector<int>(10001));
int n,m;
vector<int> res;
int deg[1000001];
bool EulerianPath()
{
      for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
               deg[i]+=g[i][j];
    
      int first=1;
      while(first<=n&&!deg[first])
         first++;
      if(first==n+1)
          return false;
          int flag=0;
          int v1=-1,v2=-1;
          for(int i=1;i<=n;i++)
            {
                if(deg[i]&1)
                 {
                     if(v1==-1)
                        v1=i;
                     else if(v2==-1)  
                        v2=i;
                    else
                       flag=1;    
                 }
            }
        if(v1!=-1)
           {
             g[v1][v2]++;
             g[v2][v1]++;
           }
           stack<int> st;
           st.push(first);
           while(!st.empty())
             {
                 int node=st.top();
                 int i=1;
                 for(i=1;i<=n;i++)
                    if(g[node][i])
                       break;
                 if(i==n+1)
                   {
                       res.push_back(node);
                       st.pop();
                   }
                 else
                 {
                     g[node][i]--;
                     g[i][node]--;
                     st.push(i);
                 }
             }
             if (v1 != -1) 
             {
              for (int i = 0; i + 1 < res.size(); ++i)
             {
             if((res[i] == v1 && res[i + 1] == v2) ||(res[i] == v2 && res[i + 1] == v1)) {
                vector<int> res2;
                for (int j = i + 1; j < res.size(); ++j)
                    res2.push_back(res[j]);
                for (int j = 1; j <= i; ++j)
                    res2.push_back(res[j]);
                res = res2;
                break;
            }
             }
        }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j])
                flag = 1;
        }
    }
  if(flag==1)
       return false;
  return true;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
      {
          int a,b;
          cin>>a>>b;
          g[a][b]++;
          g[b][a]++;
      }
    if(EulerianPath()==false)
       cout<<"IMPOSSIBLE\n";
    else
    {
        for(int i=0;i<res.size();i++)
           cout<<res[i]<<" ";
        cout<<"\n";
    }
 return 0;
}