#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix)
{
    int n=matrix.size();
    if(n==0)
         return 0;
    int m=matrix[0].size();
    int res=0;
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) 
            {
                if(matrix[i-1][j-1]=='1')
                {
                       dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
                       res=max(res,dp[i][j]);
                }
            }
        }
        return res*res;
}
int main()
{
    vector<vector<char>> matrix = {{'0','1'},{'1','0'}};
    cout<<maximalSquare(matrix);
    return 0;
}

