#include <bits/stdc++.h>
using namespace std;

//function to find the lucku numbers
//in the given matrix
vector<int> luckyNumbers (vector<vector<int>>& matrix) 
{
        int n=matrix.size();
        int m=matrix[0].size();
        int row[n];
        for(int i=0;i<n;i++)
               row[i]=INT_MAX;
        int col[m];
        for(int i=0;i<m;i++)
               col[i]=INT_MIN;
        for(int i=0;i<matrix.size();i++)
        {
          for(int j=0;j<matrix[0].size();j++)
          {
              if(row[i]>matrix[i][j]) 
                    row[i]=matrix[i][j];
          }
        }
        
        for(int i=0;i<matrix[0].size();i++)
        {
          for(int j=0;j<matrix.size();j++)
          {
              if(col[i]<matrix[j][i]) 
                    col[i]=matrix[j][i];
          }
        }
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==row[i]&&matrix[i][j]==col[j])
                {
                    res.push_back(matrix[i][j]);
                }
            }
        }
    return res;
}
int main()
{
    vector<vector<int>> matrix ={{3,7,8},
                                {9,11,13},
                                {15,16,17}};
    vector<int> lucky=luckyNumbers(matrix);
    for(int i=0;i<lucky.size();i++)
       cout<<lucky[i]<<" ";
    return 0;
}
