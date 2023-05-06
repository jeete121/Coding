#include <bits/stdc++.h>
#define N 8
using namespace std;
void printSolution(int sol[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<sol[i][j]<<"\t";
        cout<<"\n";
    }
}
bool isSafe(int x,int y,int sol[N][N])
{
    return (x>=0 && x<N && y>=0 && y<N && sol[x][y]==-1);
}
int solveKTUtil(int x,int y,int movei,int sol[N][N],int xMove[],int yMove[])
{

  if(movei==N*N)
     return true;
  for(int k=0;k<8;k++)
  {
      int next_x=x+xMove[k];
      int next_y=y+yMove[k];
      if(isSafe(next_x,next_y,sol))
      {
          sol[next_x][next_y]=movei;
          if(solveKTUtil(next_x,next_y,movei+1,sol,xMove,yMove))
              return true;
          sol[next_x][next_y]=-1;

      }
  }
  return false;
}
bool solveKT()
{
  int sol[N][N];
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
       sol[i][j]=-1;
  int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
  int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
  sol[0][0]=0;
  if(solveKTUtil(0,0,1,sol,xMove,yMove)==false)
  {
     cout<<"Solution does not exist\n";
     return false;
  }
  printSolution(sol);
  return true;
}
int main()
{
  solveKT();
  return true;
}
