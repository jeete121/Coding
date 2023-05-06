#include <bits/stdc++.h>
using namespace std;
int vis[1001][1001];
int dist[1001][1001];
int n,m;
char grid[1001][1001];
int dx[]={-1,0,1,0};
vector<int>  parent[1001][1001];
int dy[]={0,1,0,-1};
bool isValid(int x,int y)
{
   if(x<1||x>n||y<1||y>m)
      return false;
   if(vis[x][y]==1||grid[x][y]=='#'||grid[x][y]=='M')
     return false;
   return true;
}
void bfs(int x,int y)
{
   queue<pair<int,int>> q;
   q.push({x,y});
   vis[x][y]=1;
   dist[x][y]=0;
   parent[x][y]={-1,-1};
   while(!q.empty())
     {
        int currx=q.front().first;
        int curry=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
          {
             int newx=currx+dx[i];
             int newy=curry+dy[i];
             if(isValid(newx,newy))
               {
                  vis[newx][newy]=1;
                  dist[newx][newy]=dist[currx][curry]+1;
                  parent[newx][newy]={currx,curry};
                  q.push({newx,newy});
               }
          }
     }
}
void isPath()
{
       int flag=0;
    for(int i=1;i<=n;i++)
      {
         string ans="";
         if(vis[i][1]==1)
           {
              if(dist[i][1]<n*m)
                 {
                    int destx=i;
                    int desty=1;
                    int p=parent[destx][desty][0];
                    int q=parent[destx][desty][1];
        while(true)
        {
           if(p==-1&&q==-1)
                 break;
            else
            {
               if(p==destx&&q==desty+1)
                     {
                        ans+='L';
                        desty+=1;
                        p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                     }
               else if(p==destx&&q==desty-1)
                    {
                       ans+='R';
                       desty-=1;
                           p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                    }
               else if(p==destx-1&&q==desty)
                 { 
                    ans+='D';
                        destx-=1;
                        p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                 }
               else
                  {
                     ans+='U';
                       destx+=1;
                         p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                  }
               
            }
            
         }
           flag=1;
           cout<<"YES\n";
           cout<<dist[i][1]<<"\n";
           reverse(ans.begin(),ans.end());
            cout<<ans<<"\n";
         break;
        }
      }
    }
    if(flag==0)
      {
       for(int i=1;i<=m;i++)
      {
         string ans="";
         if(vis[1][i]==1)
           {
              if(dist[1][i]<n*m)
                 {
                     int destx=1;
                    int desty=i;
                    int p=parent[destx][desty][0];
                    int q=parent[destx][desty][1];
        while(true)
        {
           if(p==-1&&q==-1)
                 break;
            else
            {
               if(p==destx&&q==desty+1)
                     {
                        ans+='L';
                        desty+=1;
                        p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                     }
               else if(p==destx&&q==desty-1)
                    {
                       ans+='R';
                       desty-=1;
                           p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                    }
               else if(p==destx-1&&q==desty)
                 { 
                    ans+='D';
                        destx-=1;
                        p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                 }
               else
                  {
                     ans+='U';
                       destx+=1;
                         p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                  }
               
            }
            
         }
           flag=1;
           cout<<"YES\n";
           cout<<dist[1][i]<<"\n";
           reverse(ans.begin(),ans.end());
            cout<<ans<<"\n";
         break;
        }
      }
    }
      }
    if(flag==0)
      {
               for(int i=1;i<=m;i++)
      {
         string ans="";
         if(vis[n][i]==1)
           {
              if(dist[n][i]<n*m)
                 {
                     int destx=n;
                    int desty=i;
                    int p=parent[destx][desty][0];
                    int q=parent[destx][desty][1];
        while(true)
        {
           if(p==-1&&q==-1)
                 break;
            else
            {
               if(p==destx&&q==desty+1)
                     {
                        ans+='L';
                        desty+=1;
                        p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                     }
               else if(p==destx&&q==desty-1)
                    {
                       ans+='R';
                       desty-=1;
                           p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                    }
               else if(p==destx-1&&q==desty)
                 { 
                    ans+='D';
                        destx-=1;
                        p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                 }
               else
                  {
                     ans+='U';
                       destx+=1;
                         p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                  }
               
            }
            
         }
           flag=1;
           cout<<"YES\n";
           cout<<dist[n][i]<<"\n";
           reverse(ans.begin(),ans.end());
            cout<<ans<<"\n";
         break;
        }
      }
    }
      }
   if(flag==0)
     {
              for(int i=1;i<=n;i++)
      {
         string ans="";
         if(vis[i][m]==1)
           {
              if(dist[i][m]<n*m)
                 {
                     int destx=i;
                    int desty=m;
                    int p=parent[destx][desty][0];
                    int q=parent[destx][desty][1];
        while(true)
        {
           if(p==-1&&q==-1)
                 break;
            else
            {
               if(p==destx&&q==desty+1)
                     {
                        ans+='L';
                        desty+=1;
                        p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                     }
               else if(p==destx&&q==desty-1)
                    {
                       ans+='R';
                       desty-=1;
                           p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                    }
               else if(p==destx-1&&q==desty)
                 { 
                    ans+='D';
                        destx-=1;
                        p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                 }
               else
                  {
                     ans+='U';
                       destx+=1;
                         p=parent[destx][desty][0];
                        q=parent[destx][desty][1];
                  }
               
            }
            
         }
           flag=1;
           cout<<"YES\n";
           cout<<dist[i][m]<<"\n";
           reverse(ans.begin(),ans.end());
            cout<<ans<<"\n";
          break;
        }
      }
    }
     }
   if(flag==0)
      cout<<"NO\n";
}
int main()
{
  cin>>n>>m;
  int srcx=1,srcy=1;
  for(int i=1;i<=n;i++)
    {
       for(int j=1;j<=m;j++)
          {
             cin>>grid[i][j];
             if(grid[i][j]=='A')
               {
                  srcx=i;
                  srcy=j;
               }
       }
    }
   bfs(srcx,srcy);
   int max1=INT_MAX;
   for(int i=1;i<=n;i++)
     {
        if(vis[1][i]==1)
          {
             if(dist[1][i]<max1)
               {
                  max1=dist[1][i];
                  x=1;
                  y=i;
               }
          }
     }
   isPath();
   return 0;
   
}