#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
        int n=cost.size();
        int dp[n+1];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<=n;i++)
        {
            //if we are at last position
            if(i==n)
                  dp[i]=min(dp[i-1],dp[i-2]);

          //else
            else
                dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return dp[n];
}
int main()
{
    vector<int> cost ={10, 15, 20};
    cout<<minCostClimbingStairs(cost);
    return 0;
}