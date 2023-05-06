#include <bits/stdc++.h>
using namespace std;


int count(vector<vector<int>> &grid,int i,int j)
{
        int cnt=0;
        if(i>0&&grid[i-1][j])
               cnt++;
        if(j>0&&grid[i][j-1])
               cnt++;
        if(i<grid.size()-1&&grid[i+1][j])
               cnt++;
        if(j<grid[0].size()-1&&grid[i][j+1])
               cnt++;
        return cnt;
}
int islandPerimeter(vector<vector<int>>& grid) 
{
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j])
                   res+=(4-count(grid,i,j));
        }
        return res;
}
int main()
{
    vector<vector<int>>grid ={{0,1,0,0},
                              {1,1,1,0},
                              {0,1,0,0},
                              {1,1,0,0}};
   cout<<islandPerimeter(grid);
   return 0;
}


