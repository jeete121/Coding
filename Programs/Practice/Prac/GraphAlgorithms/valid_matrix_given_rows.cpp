#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> restoreMatrix(vector<int>& rowSum,
         vector<int>& colSum) {
        int n=rowSum.size(),m=colSum.size();
        vector<vector<int>> res(n,vector<int>(m));
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<m;j++)
              {
                  int x=min(rowSum[i],colSum[j]);
                  res[i][j]=x;
                  colSum[j]-=x;
                  rowSum[i]-=x;
              }
          }
       return res;
 }
int main()
{
   vector<int> rowSum ={3,8};
   vector<int> colSum  ={4,7};
   vector<vector<int>> matrix=restoreMatrix(rowSum,colSum);
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
          cout<<"]";
          if(i!=matrix.size()-1)
          cout<<",\n";
      }
    cout<<"]";
    return 0;
}


