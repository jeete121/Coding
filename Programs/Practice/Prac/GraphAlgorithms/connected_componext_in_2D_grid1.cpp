#include <bits/stdc++.h>
using namespace std;
char grid[10001][10001];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int vis[10001][10001];
int n,m;
bool isValid(int x,int y)
{
    if(x<1||x>n||y<1||y>m)
       return false;
    if(vis[x][y]==1||grid[x][y]=='#')
       return false;
    return true;
}
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
    //int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
             cin>>grid[i][j];
      }
      int cnt=0;
    for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
            {
                if(vis[i][j]==0&&grid[i][j]=='.')
                  {
                      cnt++;
                      dfs(i,j);
                  }
            }
      }
      cout<<cnt<<"\n";
}