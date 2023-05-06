#include <bits/stdc++.h>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) 
{
    int m=dungeon.size();
    int n=dungeon[0].size();
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {

            //if we reach at end of the grid
            if(i==m-1&&j==n-1)
            {
                //if value is positive
                if(dungeon[i][j]>0)
                       dungeon[i][j]=1;

                //if value is negative
                else
                    dungeon[i][j]=-1*dungeon[i][j]+1;
            }

          //if we are at last row
          else if(i==m-1)
          {
              //if value is positive
              if(dungeon[i][j]>0)
                     dungeon[i][j]=max(1,dungeon[i][j+1]-dungeon[i][j]);

              //if value is negative
              else
                  dungeon[i][j]=-1*dungeon[i][j]+dungeon[i][j+1];
          }

         //if we are at last column

          else if(j==n-1)
          {

              //if value is positive
               if(dungeon[i][j]>0)
                     dungeon[i][j]=max(1,dungeon[i+1][j]-dungeon[i][j]);

             //if value is negative
              else
                  dungeon[i][j]=-1*dungeon[i][j]+dungeon[i+1][j];
          }

       //if value at the current cell is positive
        else if(dungeon[i][j]>0)
        {
            
            int x=max(1,dungeon[i+1][j]-dungeon[i][j]);
            int y=max(1,dungeon[i][j+1]-dungeon[i][j]);

             //update the current cell value
            dungeon[i][j]=min(x,y);
        }

       //else the value at current cell is negative
        else
                dungeon[i][j]=-1*dungeon[i][j]+min(dungeon[i][j+1],dungeon[i+1][j]);
        }
    }
        return dungeon[0][0];
}
int main()
{
    vector<vector<int>> dungeon={{-2,-3,3},
                                 {-5,-10,1},
                                 {10,30,-5}};
    cout<<calculateMinimumHP(dungeon);
    return 0;
}