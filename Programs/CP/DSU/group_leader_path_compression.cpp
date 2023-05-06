#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int parent[100001];
int find(int a)
{
  vector<int> v;
  while(parent[a]>0)
  {
    v.push_back(a);
     a=parent[a];
  }
  for(int i=0;i<v.size();i++)
     parent[v[i]]=a;
       return a;
}
void union1(int a,int b)
{
    parent[a]+=parent[b];
    parent[b]=a;
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
       parent[i]=-1;
    while(m--)
     {
         cin>>a>>b;
         a=find(a);
         b=find(b);
         if(a!=b)
           union1(a,b);
     }
    long long int res=1;
    for(int i=1;i<=n;i++)
      if(parent[i]<0)
        res=(res*abs(parent[i]))%MOD;
    cout<<res;
}