#include <bits/stdc++.h>
using namespace std;

//all four directions
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};


//function to check for the
//current cell is valid or not
bool isValid(int x,int y,vector<vector<int>> &grid)
{
        if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&grid[x][y]==1)
              return true;
        return false;
}
int orangesRotting(vector<vector<int>>& grid) 
{
      int n=grid.size();
        if(n==0)
              return -1;
     int m=grid[0].size();
        queue<pair<int,int>> q;
    int cnt=0;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(grid[i][j]==1)
                     cnt++;
              else if(grid[i][j]==2)
                    q.push({i,j});
          }
      }
        if(cnt==0)
              return 0;
        int ans=-1;
     while(!q.empty())
     {
         ans++;
         int len=q.size();
         while(len--)
         {
             pair<int,int> p=q.front();
             q.pop();
             for(int i=0;i<4;i++)
             {
                int currx=p.first;
                int curry=p.second;
                if(isValid(currx+dx[i],curry+dy[i],grid))
                {
                  int newx=currx+dx[i];
                  int newy=curry+dy[i];
                  grid[newx][newy]=2;
                  q.push({newx,newy});
                  cnt--;
                }
             }
         }
     }
        if(cnt==0)
              return ans;
      return -1;
 }
int main()
{
    vector<vector<int>> grid ={{2,1,1},{1,1,0},{0,1,1}};
    cout<<orangesRotting(grid);
    return 0;
}
