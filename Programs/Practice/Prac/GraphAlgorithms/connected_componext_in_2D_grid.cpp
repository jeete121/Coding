#include <bits/stdc++.h>
using namespace std;
int vis[10001][10001];
int n,m;
int arr[10001][10001];
bool isValid(int x,int y)
{
    if(x<1||x>n||y<1||y>m)
       return false;
    if(vis[x][y]==1||arr[x][y]==0)
        return false;
    return true;
}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
      {
          if(isValid(x+dx[i],y+dy[i]))
             dfs(x+dx[i],y+dy[i]);
      }
}
int main()
{
    int cnt=0;
    cin>>n>>m;
    //int arr[n+1][m+1];
    for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
             {
              cin>>arr[i][j];
             }
      }
    for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
            {
                if(arr[i][j]==1&&vis[i][j]==0)
                   {
                       cnt++;
                       dfs(i,j);
                   }
            }
      }
      cout<<cnt<<"\n";
    return 0;
}