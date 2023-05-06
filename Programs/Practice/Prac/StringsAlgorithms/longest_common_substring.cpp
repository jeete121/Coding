/*
Longest Common Substring:
Time Complexity O(N*M)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
string LCS(string X,string Y,int n,int m)
{
    //int dp[n+1][m+1];
    int len=0,index=0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
            {
                if(X[i-1]==Y[j-1])
                   {
                       dp[i][j]=1+dp[i-1][j-1];
                       if(dp[i][j]>len)
                         {
                             len=dp[i][j];
                             index=i;
                         }
                   }
                  else
                    dp[i][j]=dp[i-1][j-1];
            }
      }
      return X.substr(index-len,len);
}
int main()
{
  string X,Y;
  cin>>X>>Y;

  cout<<LCS(X,Y,X.size(),Y.size())<<"\n";
//   for(int i=0;i<=X.size();i++)
//     {
//         for(int j=0;j<=Y.size();j++)
//            cout<<dp[i][j]<<" ";
//         cout<<"\n";

//     }
  return 0;
}