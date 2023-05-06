#include <bits/stdc++.h>
using namespace std;

//function to the number
//of ways to reach to the top
//of stairs
int climbStairs(int n)
{
    int dp[n+1];
    if(n==0)
         return 1;
    dp[0]=1;
    dp[1]=1;
    if(n==1)
         return dp[1];

    //we move either 1 or 2 steps
    for(int i=2;i<=n;i++)
       dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}
int main()
{
    int n=8;
    int ways=climbStairs(n);
    cout<<ways<<"\n";
    return 0;
}

