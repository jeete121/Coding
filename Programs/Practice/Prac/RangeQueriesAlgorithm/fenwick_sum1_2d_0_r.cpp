#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int bit[1001][1001];
int n,m;
int sum(int x,int y)
{
    int res=0;
    for(int i=x;i>=0;i=(i&(i+1))-1)
      {
          for(int j=y;j>=0;j=(j&(j+1))-1)
             res+=bit[i][j];
      }
    return res;
}
void add(int x,int y,int delta)
{
    for(int i=x;i<n;i=i|(i+1))
       {
           for(int j=y;j<n;j=j|(j+1))
              bit[i][j]=delta;
       }
}
void buildTree()
{
    for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
            add(i,j,arr[i][j]);
      }
}
int main()
{
   cin>>n>>m;
   for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
             cin>>arr[i][j];
      }
    buildTree();
    int q;
    cin>>q;
    while(q--)
      {
          int x,y;
          cin>>x>>y;
          cout<<sum(x,y)<<"\n";
      }
    return 0;
} 