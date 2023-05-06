#include <bits/stdc++.h>
using namespace std;
int S[101],T[101],FT[201];
int timer;
vector<int> arr[10001];
void dfs(int node,int par)
{
    S[node]=timer;
    FT[timer]=node;
    timer++;
    for(int child:arr[node])
      {
          if(child!=par)
             dfs(child,node);
      }
    T[node]=timer;
    FT[timer]=node;
    timer++;
}
int main()
{
   int n,a,b;
   cin>>n;
   for(int i=1;i<n;i++)
      {
          cin>>a>>b;
          arr[a].push_back(b);
          arr[b].push_back(a);
      }
    timer=1;
    dfs(1,-1);
    cout<<"START\n";
    for(int i=1;i<=n;i++)
       cout<<S[i]<<" ";
    cout<<"\n";
    cout<<"END\n";
    for(int i=1;i<=n;i++)
       cout<<T[i]<<" ";
    cout<<"\n";
    cout<<"FLAT TREE\n";
    for(int i=1;i<=2*n;i++)
       cout<<FT[i]<<" ";
    cout<<"\n";
    return 0;
}