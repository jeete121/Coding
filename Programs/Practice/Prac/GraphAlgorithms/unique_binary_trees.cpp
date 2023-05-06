#include <bits/stdc++.h>
using namespace std;

//functio to count number of unique binary trees
int numTrees(int m) 
{
    int dp[m+1];
        memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    for(int n=2;n<=m;n++)
      {
          for(int i=1;i<=n;i++)
                dp[n]=dp[n]+dp[n-i]*dp[i-1];
      }
        return dp[m];
}
int main()
{
    int n=3;
    cout<<numTrees(n);
    return 0;
}


