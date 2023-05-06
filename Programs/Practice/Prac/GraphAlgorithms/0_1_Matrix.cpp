#include <bits/stdc++.h>
using namespace std;

//function to check if current cell is valid
//or not
bool isSafe(vector<vector<int>> &matrix,int i,int j)
{
        int n=matrix.size();
        int m=matrix[0].size();
        return (i>=0 &&i<n)&&(j>=0&&j<m)&&(matrix[i][j]==0||matrix[i][j]==1);
        
}

//bfs funtion 
int bfs(vector<vector<int>>&matrix,int x,int y,int n)
{
        queue<pair<int,int>>q;
        q.push({x,y});
        int res=0;
        while(!q.empty())
        {
            int len=q.size();
            while(len--)
            {
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                if(matrix[x][y]==0)
                      return res;
                else
                {
                    if(isSafe(matrix,x,y+1))
                          q.push({x,y+1});
                    if(isSafe(matrix,x,y-1))
                          q.push({x,y-1});
                    if(isSafe(matrix,x+1,y))
                          q.push({x+1,y});
                    if(isSafe(matrix,x-1,y))
                          q.push({x-1,y});
                }
               
            }
             res++;
        }
        return res;
}

//function  to update the matrix
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
{
       int n=matrix.size();
       int m=matrix[0].size();
        vector<vector<int>> res=matrix;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(res[i][j]==0)
                      continue;
              else
                   res[i][j]=bfs(matrix,i,j,n);
           }
       }
        return res;
}
int main()
{
 vector<vector<int>> matrix={{0,0,0},
                             {0,1,0},
                             {1,1,1}};
  matrix=updateMatrix(matrix);
  cout<<"[";
  for(int i=0;i<matrix.size();i++)
    {
         cout<<"[";
        for(int j=0;j<matrix[i].size();j++)
          {
              if(j!=matrix[i].size()-1)
                cout<<matrix[i][j]<<",";
              else
                cout<<matrix[i][j];
              
          }
          if(i!=matrix.size()-1)
             cout<<"],\n";
          else
           cout<<"]";
    }
    cout<<"]";
}
