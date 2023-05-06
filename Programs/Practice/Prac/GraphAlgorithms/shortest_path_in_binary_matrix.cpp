#include <bits/stdc++.h>
using namespace std;


//define all 8 directions
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int vis[1001][1001];
int dist[1001][1001];

//function to check for
//the cuurent cell is valid or not
bool isValid(int x,int y,vector<vector<int>> &grid)
{
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size())
              return false;
         if(vis[x][y]==1||grid[x][y]==1)
               return false;
        return true;
}

//bfs function 
void bfs(int srcx,int srcy,vector<vector<int>> &grid)
{
        queue<pair<int,int>> q;
        q.push({srcx,srcy});
        dist[srcx][srcy]=1;

        //iterate till the queue is not
        //empty
        while(!q.empty())
        {
            int currx=q.front().first;
            int curry=q.front().second;
            q.pop();
            for(int i=0;i<8;i++)
            {
                if(isValid(currx+dx[i],curry+dy[i],grid))
                {
                    int newx=currx+dx[i];
                    int newy=curry+dy[i];
                    q.push({newx,newy});
                    vis[newx][newy]=1;
                    dist[newx][newy]=dist[currx][curry]+1;
                }
            }
        }
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
        int n=grid.size();
        if(n==0)
              return 0;
        int m=grid[0].size();
        if(grid[0][0]==1||grid[n-1][m-1]==1)
            return -1;
        bfs(0,0,grid);
        if(dist[n-1][m-1]==0&&n!=1&&m!=1)
              return -1;
        return dist[n-1][m-1];
}

int main()
{
   vector<vector<int>> grid ={{0,1},{1,0}};
   cout<<shortestPathBinaryMatrix(grid);
   return 0;
}
