#include <bits/stdc++.h>
using namespace std;


int oddCells(int n, int m, vector<vector<int>>& indices) 
{
        int grid[n][m];
        memset(grid,0,sizeof(grid));
        for(int i=0;i<indices.size();i++)
         {
            int x=indices[i][0];
            int y=indices[i][1];
            for(int k=0;k<m;k++)
                   grid[x][k]++;
            for(int k=0;k<n;k++)
                   grid[k][y]++;
         }
        int cnt=0;
        for(int i=0;i<n;i++)
              for(int j=0;j<m;j++)
                     if(grid[i][j]&1)
                            cnt++;
        return cnt;
} 
int main()
{
   int n = 2, m = 3;
   vector<vector<int>> indices ={{0,1},{1,1}};
   cout<<oddCells(n,m,indices);
   return 0;
}
