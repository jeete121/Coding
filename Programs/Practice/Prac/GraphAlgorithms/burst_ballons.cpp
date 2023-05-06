#include <bits/stdc++.h>
using namespace std;


long long int maxCoins(vector<int>& nums) 
{
        if(nums.size()==0)
              return 0;
        long long int dp[nums.size()][nums.size()];
        memset(dp,0,sizeof(dp));
        //check for all subarray length
        for(int len=1;len<=nums.size();len++)
        {
            for(int i=0;i<=nums.size()-len;i++)
            {
                int j=len+i-1;
                //check all values of the subarray from i to j;
                for(int k=i;k<=j;k++)
                {
                   long long  int left=1;
                    int right=1;
                    if(i!=0)
                         left=nums[i-1];
                    if(j!=nums.size()-1)
                           right=nums[j+1];
                    int before=0;
                    int after=0;
                    if(i!=k)
                          before=dp[i][k-1];
                    if(j!=k)
                          after=dp[k+1][j];
                    dp[i][j]=max(dp[i][j],left*nums[k]*right+before+after);
                }
            }
        }
        return dp[0][nums.size()-1];
}
int main()
{
    vector<int> nums ={3,1,5,8};
    cout<<maxCoins(nums);
    return 0;
}

