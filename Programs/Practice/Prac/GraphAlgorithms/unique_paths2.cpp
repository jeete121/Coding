#include <bits/stdc++.h>
using namespace std;


//function to find the number of 
//paths from top left corner to
//bottom right corner in the grid 
//with some obstacles
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{

    int m=obstacleGrid.size();

    //if grid is empty
    if(m==0)
        return 0;
    int n=obstacleGrid[0].size();
    int dp[m][n];
    for(int i=0;i<m;i++)
        {
        
            if(obstacleGrid[i][0]==1)
            {
                while(i<m)
                {
                    dp[i][0]=0;
                    i++;
                }
            }
            else
                dp[i][0]=1;
        }
     for(int i=0;i<n;i++)
        {
            if(obstacleGrid[0][i]==1)
            {
                while(i<n)
                {
                    dp[0][i]=0;
                    i++;
                }
            }
            else
                dp[0][i]=1;
        }

    //find all the paths in dp array
      for(int i=1;i<m;i++)
      {
          for(int j=1;j<n;j++)
          {

              //if obstacle then dp[i][j]=0
              if(obstacleGrid[i][j]==1)
                     dp[i][j]=0;
             //else update with sum of previous two
              else
                  dp[i][j]=dp[i-1][j]+dp[i][j-1];
          }
      }
        return dp[m-1][n-1];
}
int main()
{
     vector<vector<int>> obstacleGrid = {{0,0,0},
                                        {0,1,0},
                                        {0,0,0}};
     int paths=uniquePathsWithObstacles(obstacleGrid);
     cout<<paths<<"\n";
     return 0;
}
