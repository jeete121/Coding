#include <bits/stdc++.h>
using namespace std;


int maxProfit(vector<int>&prices,bool f,int day,
      vector<vector<int>>&dp)
{
    //base case
    if(day>=prices.size())
            return 0;

    //if already calculated
    if(dp[f][day]!=-1)
          return dp[f][day];

    //if f is false
    if(!f)
      {
           
            int x = maxProfit(prices,!f,day+1,dp) - prices[day];
            int y = maxProfit(prices,f,day+1,dp);
             dp[f][day] = max(x,y);
       }
    //ele
    else
        {
			int x  = prices[day] + maxProfit(prices,!f,day+2,dp);
			int y  = maxProfit(prices,f,day+1,dp);
       dp[f][day] = max(x,y);}
        return dp[f][day];
}

int maxProfit(vector<int>& prices)
{
        vector<vector<int>>dp(2,vector<int>(prices.size(),-1));
        return maxProfit(prices,false,0,dp);
}

int main()
{
   vector<int> prices= {1,2,3,0,2};
   cout<<maxProfit(prices);
   return 0;
}