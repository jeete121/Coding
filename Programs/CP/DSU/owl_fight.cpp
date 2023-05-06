#include <bits/stdc++.h>
using namespace std;
int parent[1000001];
int find(int a)
{
    if(parent[a]<0)
       return a;
    int x=find(parent[a]);
    parent[a]=x;
    return x;
}
void union1(int a,int b)
{
    parent[a]=min(parent[a],parent[b]);
    parent[b]=a;
}
int main()
{
  int n,m,a,b,q,x,y;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    parent[i]=-i;
  while(m--)
   {
       cin>>a>>b;
       a=find(a);
       b=find(b);
       if(a!=b)
         union1(a,b);
   }
   cin>>q;
   while(q--)
    {
        cin>>a>>b;
        x=a;
        y=b;
        a=find(a);
        b=find(b);
        if(a==b)
          cout<<"TIE\n";
        else
         {
             if(parent[a]<parent[b])
               cout<<x<<"\n";
             else
              cout<<y<<"\n";
         }
    }
}