#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int EDIT(string X,string Y,int n,int m)
{
   if(n==0||m==0)
      return max(n,m);
    if(dp[n-1][m-1]!=-1)
        return dp[n-1][m-1];
    else
    {
    
    if(X[n-1]==Y[m-1])
       dp[n-1][m-1]= EDIT(X,Y,n-1,m-1);
    else
        dp[n-1][m-1]= 1+min(EDIT(X,Y,n-1,m),min(EDIT(X,Y,n,m-1),EDIT(X,Y,n-1,m-1)));
    return dp[n-1][m-1];
    }
    
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    string X,Y;
    cin>>X>>Y;
    int n=X.size(),m=Y.size();
    memset(dp,-1,sizeof(dp));
    cout<<EDIT(X,Y,n,m)<<"\n";
    }
    return 0;
}