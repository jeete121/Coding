#include <bits/stdc++.h>
using namespace std;

//varible to hold the final
//answer
int res=0;
void dfs(int i,int j,int n,int m,vector<vector<int>>&grid,
        int x,int cnt)
{
        //if the cell is not in the boudary
        if(i<0||i>=n||j<0||j>=m||grid[i][j]==-1)
               return;

        //if we reach to the final position
      if(grid[i][j]==2)
        {
            if(x+1==cnt)
                  res++;
            return;
        }
        grid[i][j]=-1;

        //call for down 
        dfs(i+1,j,n,m,grid,x,cnt+1);

        //call for up
        dfs(i-1,j,n,m,grid,x,cnt+1);
        
        //call for right
        dfs(i,j+1,n,m,grid,x,cnt+1);

        //call for left
        dfs(i,j-1,n,m,grid,x,cnt+1);
         grid[i][j]=0;
    
}

//function to find all unique
//paths from given starting position
//to the given end position
int uniquePaths(vector<vector<int>>& grid) 
{
    int n=grid.size();
   //empty grid
   if(n==0)
          return 0;
    int m=grid[0].size();
    int row,col,x=0;


     for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    row=i;
                    col=j;
                }

              //count of empty squre
                if(grid[i][j]==0)
                       x++;
            }
        }

    //call dfs for the start position and count of
    //number of empty cell
        dfs(row,col,n,m,grid,x,0);
        return res;
}

int main()
{
    vector<vector<int>> grid={{1,0,0,0},
                             {0,0,0,0},
                            {0,0,2,-1}};
    int paths=uniquePaths(grid);
    cout<<paths<<"\n";
    return 0;
}