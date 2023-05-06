#include <bits/stdc++.h>
using namespace std;
int dp[10000][10000];
int minDeletion(string str,int i,int j)
{
    if(i>=j)
      return 0;
    if(dp[i][j]!=-1)
      return dp[i][j];
    if(str[i]==str[j])
      {
          dp[i][j]= minDeletion(str,i+1,j-1);
          return dp[i][j];
      }
    else
    {
      dp[i][j]= 1+min(minDeletion(str,i,j-1),minDeletion(str,i+1,j));
     return dp[i][j];
    }
}
    
int main()
{
   string str;
   cin>>str;
   memset(dp,-1,sizeof(dp));
   cout<<minDeletion(str,0,str.size()-1);
   return 0;
}