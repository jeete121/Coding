#include <bits/stdc++.h>
using namespace std;
#define N 4
void printSol(int board[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<board[i][j]<<" ";
        cout<<"\n";
    }

}
bool isSafe(int board[N][N],int row,int col)
{
    for(int i=0;i<col;i++)
        if(board[row][i])
           return false;
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
      if(board[i][j])
         return false;
    for(int i=row,j=col;i<N && j>=0;i++,j--)
        if(board[i][j])
          return false;
    return true;
}
bool solveNQUtil(int board[N][N],int col)
{
      if(col==N)
        return true;
    for(int i=0;i<N;i++)
    {
        if(isSafe(board,i,col))
        {
          board[i][col]=1;
          if(solveNQUtil(board,col+1))
             return true;
          board[i][col]=0; //backtrack
        }
    }
  return false;
}
bool solveNQ(int board[N][N])
{
    if(solveNQUtil(board,0)==false)
    {
        cout<<"Solution does not exist\n";
        return false;
    }
    printSol(board);
    return true;
}
int main()
{
   int board[N][N];
   for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
          board[i][j]=0;
    //board[0][0]=1;
   solveNQ(board);
   return 0;
}
