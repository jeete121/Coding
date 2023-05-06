#include <bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>>& grid) 
{
     int count=0;
     for(int i=0;i<grid.size();i++)
     {
         
         sort(grid[i].begin(),grid[i].end());
         int index=lower_bound(grid[i].begin(),grid[i].end(),0)-grid[i].begin();

         count+=abs(index);
         
     }
        return count;
}
int main()
{
    vector<vector<int>> grid ={{4,3,2,-1},
                              {3,2,1,-1},
                              {1,1,-1,-2},
                              {-1,-1,-2,-3}};
    cout<<countNegatives(grid);
    return 0;
}