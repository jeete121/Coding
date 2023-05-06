#include <bits/stdc++.h>
using namespace std;
#define N 4
#define M 4
int countways(int maze[N][M])
{
    if(maze[0][0]==-1)
        return 0;
    for(int i=0;i<N;i++)
      {
         if(maze[i][0]==0)
                maze[i][0]=1;
         else
            break;
      }
    for(int i=1;i<M;i++)
    {
        if(maze[0][i]==0)
            maze[0][i]=1;
        else
            break;
    }
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<M;j++)
        {
          if(maze[i][j]==-1)
              continue;
          if(maze[i-1][j]>0)
             maze[i][j]=maze[i][j]+maze[i-1][j];
          if(maze[i][j-1]>0)
              maze[i][j]=maze[i][j]+maze[i][j-1];
        }
    }
    if(maze[N-1][M-1]>0)
         return maze[N-1][M-1];
    return 0;
}
void printMaze(int maze[N][M])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
             cout<<maze[i][j]<<"\t";
        cout<<"\n";
    }
}
int main()
{
       int maze[N][M] =  {{0,  0, 0, 0},
                       {0, -1, 0, 0},
                       {-1, 0, 0, 0},
                       {0,  0, 0, 0}};

    cout<<countways(maze)<<"\n";
    printMaze(maze);
    return 0;
}
