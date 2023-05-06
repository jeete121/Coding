#include <bits/stdc++.h>
using namespace std;
//store the visted node
int visited[1001][1001];
//direction up,right,down,left
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
//function to find the
//bfs traversal of 2d grid
void bfs2Dgrid(int x,int y,int n,int m,int grid[][3])
{
    //queue pair to store the 
    //coordinates of the cell
    queue<pair<int,int>> q;
    //mark the current cell
    //as visited
    visited[x][y]=1;
   //push the current cell into
   //the queue
    q.push({x,y});
    //iterate till queue
    //is not empty
    while(!q.empty())
     {
      //current x
       x=q.front().first;
       //current y
       y=q.front().second;
       //print the current cell data
       cout<<grid[x][y]<<" ";
       //pop the first element from the 
       //queue
       q.pop();
       //iterate for all 
       //the directions
       for(int i=0;i<4;i++)
        {
          //new x
          int newx=x+dx[i];
          //new y
          int newy=y+dy[i];
          //if cell is valid and not visted
          if(newx>=0&&newx<n&&newy>=0&&newy<m&&visited[newx][newy]==0)
             {
                //push into  the queue
                 q.push({newx,newy});
                //mark as visited
                 visited[newx][newy]=1;
             }
       }
    }
}
int main()
{
 //2d grid input
  int grid[][3]={{1,2,3},{4,5,6},{7,8,9}};
  //dimensions of the grid
  int n=3,m=3;
  cout<<"BFS traversal of 2d grid is\n";
  bfs2Dgrid(0,0,n,m,grid);
  return 0;
}