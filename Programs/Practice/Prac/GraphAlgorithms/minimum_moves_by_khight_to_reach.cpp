#include <bits/stdc++.h>
using namespace std;
int dist[1001][10001];
int vis[1001][10001];
int n,m;
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
bool isValid(int x,int y)
{
    if(x<1||x>n||y<1||y>m)
       return false;
    if(vis[x][y]==1)
       return false;
    return true;
}
void bfs(int srcx,int srcy)
{
    queue<pair<int,int>> q;
    q.push({srcx,srcy});
    dist[srcx][srcy]=0;
    vis[srcx][srcy]=1;
    while(!q.empty())
    {
        int currx=q.front().first;
        int curry=q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
          {
              if(isValid(currx+dx[i],curry+dy[i]))
                {
                    int newx=currx+dx[i];
                    int newy=curry+dy[i];
                    vis[newx][newy]=1;
                    dist[newx][newy]=dist[currx][curry]+1;
                    q.push({newx,newy});
                }
          }
    }

}
int main()
{
    cin>>n>>m;
    int srcx,srcy,dest_x,dest_y;
    cin>>srcx>>srcy;
    cin>>dest_x>>dest_y;
    bfs(srcx,srcy);
    cout<<dist[dest_x][dest_y]<<"\n";
    return 0;
}