#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr[1000001];
vector<int> color,parent;
int cycle_start,cycle_end;
bool dfs(int node,int par)
{
    color[node]=1;
    for(int child:arr[node])
      {
          if(child==par)
             continue;
          if(color[child]==0)
             {
                 parent[child]=node;
                 if(dfs(child,parent[child]))
                       return true;
             }
          else if(color[child]==1)
             {
                 cycle_start=child;
                 cycle_end=node;
                 return true;
             }
      }
     color[node]=2;
     return false;
}
void find_cycle()
{
    color.assign(n+1,0);
    parent.assign(n+1,-1);
    cycle_start=-1;
    for(int i=1;i<=n;i++)
        if(color[i]==0&&dfs(i,parent[i]))
            break;
    if(cycle_start==-1)
       cout<<"Acyclic\n";
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for(int v=cycle_end;v!=cycle_start;v=parent[v])
           cycle.push_back(v);
        cycle.push_back(cycle_start);
        cout<<"Cycle Found:\n";
        reverse(cycle.begin(),cycle.end());
        for(int v:cycle)
             cout<<v<<" ";
       cout<<"\n";
    }
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
     find_cycle();
     return 0;
}