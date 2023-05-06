#include <bits/stdc++.h>
using namespace std;
int main()
{ 
   
   vector<vector<int>> mat={{1 ,2, 3},
                            {4, 5, 6},
                            {9, 8, 9}};
    int sum1=0,sum2=0;
    int n=mat.size();
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
        {
         if(i==j)
              sum1=sum1+mat[i][j];
         if(i==n-1-j)
             sum2=sum2+mat[i][j];
        }
    }
  int res=abs(sum1-sum2);
  cout<<res<<"\n";
  return 0;
}
