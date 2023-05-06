
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

//function to find the 
//longest commonn subsequence
int LCS(string X,string Y,int n,int m)
{
   //base case if any string is empty
   //return 0
    if(n==0||m==0)
       return 0;
   
   //if already calculated return
   //that value
    if(dp[n-1][m-1]!=-1)
       return dp[n-1][m-1];

    //if last character is same in both
    //then
    if(X[n-1]==Y[m-1])
       dp[n-1][m-1]=1+LCS(X,Y,n-1,m-1);

   //last character is not same
    else
      dp[n-1][m-1]=max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1));
    return dp[n-1][m-1];
}
int main()
{
  string X="ABCD";
  string Y="BD";
  memset(dp,-1,sizeof(dp));
  int n=X.size(),m=Y.size();
  cout<<LCS(X,Y,n,m)<<"\n";
  return 0;
}
//Time Complexity:O(n*m)