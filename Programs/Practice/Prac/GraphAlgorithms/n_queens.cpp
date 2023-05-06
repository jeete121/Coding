#include <bits/stdc++.h>
using namespace std;
#define N 10

//check for the current cell
//is safe or not
bool is_safe(int board[][N],int row,int col,int n)
{
   int i,j;
   for(i=0;i<col;i++)
      if(board[row][i])
	     return false;
   for(i=row,j=col;i>=0&&j>=0;i--,j--)
         if(board[i][j])
		    return  false;
   for(i=row,j=col;j>=0&&i<n;i++,j--)
       if(board[i][j]) 
	      return false;
	return true;
	
}

//function to  check if N queeen can be placed or not
//and find where they are places
bool N_Queen(int board[][N],int col,int n)
{
	if(col>=n)
	   return true;
	for(int i=0;i<n;i++)
	  {
              
              //if safe then mark it as palce for
              //queen
			  if(is_safe(board,i,col,n)==true)
				{
			    	board[i][col]=1;
				  if(N_Queen(board,col+1,n)==true)
				   return true;
                 //backtrack
				board[i][col]=0;
				}
	  }
    return false;
}
int main()
{
	int n=4;
	int board[10][10];
	for(int i=0;i<n;i++)
	  {
		  for(int j=0;j<n;j++)
		      board[i][j]=0;
	  }
	  bool flag=N_Queen(board,0,n);
	  for(int i=0;i<n;i++)
	     {
			 for(int j=0;j<n;j++)
			  {
				  cout<<board[i][j]<<" ";
			  }
			  cout<<"\n";

		 }
    return 0;
}