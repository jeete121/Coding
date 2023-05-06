#include <bits/stdc++.h>
using namespace std;

int dp[510][501];
int stoneGame(int l,int r,vector<int> &piles)
{
        if(dp[l][r]!=-1)
              return dp[l][r];
        if(r-l==1)
              dp[l][r]= max(piles[l],piles[r]);
        else
              dp[l][r]=max(piles[l]+stoneGame(l+1,r,piles),piles[r]+stoneGame(l,r-1,piles));
        return dp[l][r];
}
bool stoneGame(vector<int>& piles) 
{
        int n=piles.size();
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
              sum+=piles[i];
        int alex=stoneGame(0,n-1,piles);
         if(alex>sum-alex)
               return true;
        return false;
}

int main()
{
    vector<int> piles ={5,3,4,5};
    if(stoneGame(piles))
      cout<<"true";
    else
      cout<<"false";

    return 0;
    
    
}