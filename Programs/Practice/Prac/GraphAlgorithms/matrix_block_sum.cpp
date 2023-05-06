#include <bits/stdc++.h>
using namespace std;

//function to find the block sum of the matrix
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, 
int K) 
{
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> res=mat; 
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
                  res[i][j]+=res[i][j-1];
        }
        for(int i=0;i<m;i++)
              for(int j=1;j<n;j++)
                     res[j][i]+=res[j-1][i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int col=min(m-1,j+K),row=min(n-1,i+K);
                ans[i][j]=res[row][col];
                if(i-K-1>=0)
                      ans[i][j]-=res[i-K-1][col];
               if(j-K-1>=0)
                      ans[i][j]-=res[row][j-K-1];
               if(i-K-1>=0&&j-K-1>=0)
                      ans[i][j]+=res[i-K-1][j-K-1];
            }
        }
        return ans;
}
int main()
{
  vector<vector<int>> mat ={{1,2,3},
                            {4,5,6},
                            {7,8,9}};
  int K = 1;
  mat=matrixBlockSum(mat,K);
  cout<<"[";
  for(int i=0;i<mat.size();i++)
    {
       cout<<"[";
       for(int j=0;j<mat[i].size();j++)
         {
             if(j!=mat[i].size()-1)
               cout<<mat[i][j]<<",";
             else
              cout<<mat[i][j];
         }
         if(i!=mat.size()-1)
            cout<<"],";
         else
          cout<<"]";
    }
  cout<<"]";
  return 0;
}
