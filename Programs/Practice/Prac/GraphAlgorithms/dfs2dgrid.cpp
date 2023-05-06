#include <bits/stdc++.h>
using namespace std;
//store the visted node
int visited[1001][1001];
//direction up,right,down,left
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
//function to find the 
//dfs traversal on 2d grid
void dfs2Dgrid(int x,int y,int n,int m,int grid[][3])
{
    //mark the current cell 
    //as visited
    visited[x][y]=1;
    //print the current node data
    cout<<grid[x][y]<<" ";
    //iterate for all the 
    //directions
    for(int i=0;i<4;i++)
      {
        //new x
        int newx=dx[i]+x;
        //new y
        int newy=dy[i]+y;
        //if valid and not visited
        if(newx>=0&&newx<n&&newy>=0&&newy<m&&visited[newx][newy]==0)
        {
            //call dfs function
                dfs2Dgrid(newx,newy,n,m,grid);
         }
      }
}
int main()
{
 //2d grid input
  int grid[][3]={{1,2,3},{4,5,6},{7,8,9}};
  //dimensions of the grid
  int n=3,m=3;
  cout<<"DFS traversal of 2d grid is\n";
  dfs2Dgrid(0,0,n,m,grid);
  return 0;
}