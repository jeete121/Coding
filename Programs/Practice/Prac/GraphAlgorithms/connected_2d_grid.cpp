#include <bits/stdc++.h>
using namespace std;
//visted to hold the visited cell
int visited[1001][1001];
//all four directions
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
//funtion to check the
//validation of the cell
bool isValid(int x,int y,int n,int m,int grid[][4])
{
    //if cell is out of boundary
    //return false
     if(x<0||x>=n||y<0||y>=m)
        return false;
    //if the cell is alredy visited or
    //it is not grid[x][y]==0
    //return false
     if(visited[x][y]==1||grid[x][y]==0)
        return false;
    //else return true
     return true;
}
void dfs2Dgrid(int x,int y,int n,int m,int grid[][4])
{
    //mark the current cell as visited
    visited[x][y]=1;
    //iterate for all the directions
    for(int i=0;i<4;i++)
      {
          //new x
          int newx=x+dx[i];
          //new y
          int newy=y+dy[i];
          //if the new cell is valid
          if(isValid(newx,newy,n,m,grid))
            {
                //run dfs on it
                dfs2Dgrid(newx,newy,n,m,grid);
            }
      }
}
int main()
{
    //input as 2d grid 1 means include in 
    //component 0 means not inlcude in component
    int grid[][4]={{1,1,0,0},{0,1,0,0},{1,0,0,1},{1,1,0,1}};
    //dimensions of the grid
    int n=4,m=4;
    //varibale to hold the connected
    //components
    int connected_components=0;
    for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
          {
              //if grid[i][j]==1 and it is not visited
              //run 2d dfs on it
              if(grid[i][j]==1&&visited[i][j]==0)
               {
                   //increment the connected
                   //components
                   connected_components++;
                   //call the dfs
                   dfs2Dgrid(i,j,n,m,grid);
               }
          }
     }
     cout<<"No of connnected components are\n";
     cout<<connected_components<<"\n";
     return 0;
}