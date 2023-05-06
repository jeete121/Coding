#include <bits/stdc++.h>
using namespace std;

//function to find the diagonal 
//traversal of matrix
vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
{
      int i=0,j=0;
      bool flag=true;
      vector<int> res;
      int cnt=0;
        int n=matrix.size();
        if(n==0)
              return res;
        int m=matrix[0].size();

    //iterate till the count is
    //less than n*m
    while(cnt<n*m)
      {
          //if flag is true up
          if(flag)
          {
            
            for(;i>=0&&j<m;j++,i--)
              {
                  res.push_back(matrix[i][j]);
                  cnt++;
              }
              if(i<0&&j<m)
                    i=0;
             if(j==m)
             {
                 i=i+2;
                 j--;
             }
          }

          //else move down 
          else
          {
              for(;j>=0&&i<n;j--,i++)
              {
                  res.push_back(matrix[i][j]);
                  cnt++;
              }
              if(j<0&&i<n)
                     j=0;
              if(i==n)
              {
                  j=j+2;
                  i--;
              }
          }
          //change direction
          flag=!flag;
      }
        return res;
}
int main()
{
    vector<vector<int>> matrix={{ 1, 2, 3 },
                            { 4, 5, 6 },
                            {7, 8, 9 }};
    vector<int> res=findDiagonalOrder(matrix);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
  return 0;
}

