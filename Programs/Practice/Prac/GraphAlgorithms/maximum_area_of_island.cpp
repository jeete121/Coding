#include <bits/stdc++.h>
using namespace std;


int n,m;
int vis[100][100];

//funtion to check the cell
//is  valid or not
bool isValid(int x,int y,vector<vector<int>> &grid)
{

    //if cell is not in the boundary
      if(x<0||x>=n||y<0||y>=m)
              return false;
      //if cell is already visited or
      //thier is no island
      if(vis[x][y]==1||grid[x][y]==0)
            return false;
      return true;
}
int cnt;

//all for directions
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

//dfs for the 2d grid
void dfs(int x,int y,vector<vector<int>> &grid)
{
    //mark the current cell as
    //visited
    vis[x][y]=1;

    //increment the count
    cnt++;
    //iterate for all four directions
      for(int i=0;i<4;i++)
      {
          if(isValid(dx[i]+x,dy[i]+y,grid))
          {
              dfs(x+dx[i],y+dy[i],grid);
          }
      }
}

//function to find the maximum area
//of island
int maxAreaOfIsland(vector<vector<int>>& grid) 
{
        n=grid.size();
        if(n==0)
              return 0;
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0&&grid[i][j]==1)
                {
                    cnt=0;
                    dfs(i,j,grid);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
}
int main()
{
  vector<vector<int>> grid={{0,0,1,0,0,0,0,1,0,0,0,0,0},
                            {0,0,0,0,0,0,0,1,1,1,0,0,0},
                            {0,1,1,0,1,0,0,0,0,0,0,0,0},
                            {0,1,0,0,1,1,0,0,1,0,1,0,0},
                            {0,1,0,0,1,1,0,0,1,1,1,0,0},
                            {0,0,0,0,0,0,0,0,0,0,1,0,0},
                            {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,0,0,0,0,0,0,1,1,0,0,0,0}};
  int area=maxAreaOfIsland(grid);
  cout<<area<<"\n";
  return 0;
}
