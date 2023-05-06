#include <bits/stdc++.h>
using namespace std;

//function to count the special position in
//binary matrix
int numSpecial(vector<vector<int>>& mat)
{
     int n=mat.size(),m=mat[0].size();
     int cnt=0;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             if(mat[i][j]==1)
             {
                 int flag=0;
                 for(int k=0;k<m;k++)
                 {
                     if(k!=j)
                     {
                         if(mat[i][k]!=0)
                         {
                             flag=1;
                             break;
                         }
                     }
                 }
                 if(flag==0)
                 {
                     for(int k=0;k<n;k++)
                     {
                         if(k!=i)
                         {
                             if(mat[k][j]!=0)
                             {
                                 flag=1;
                                 break;
                             }
                         }
                     }
                 }
                if(flag==0)
                      cnt++;
             }
         }
     }
        return cnt;
}
int main()
{
  vector<vector<int>> mat = {{1,0,0},
                             {0,0,1},
                             {1,0,0}};
  cout<<numSpecial(mat);
  return 0;
}