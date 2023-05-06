#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) 
{
        int n=nums.size();
        if(n==1||n==0)
              return nums;
        vector<int> dp[n];
        sort(nums.begin(),nums.end());
        dp[0].push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
             {
                if(nums[i]>nums[j] && dp[j].size()>dp[i].size() &&(nums[i]%nums[j]==0||nums[j]%nums[i]==0))
                       dp[i]=dp[j];
             }
            dp[i].push_back(nums[i]);
        }

        // for(int i=0;i<n;i++)
        //   {
        //       for(int j=0;j<dp[i].size();j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        //   }
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i].size()>dp[j].size())
            {
                j=i;
            }
        }
        return dp[j];               
}
int main()
{
    vector<int> nums ={1,2,3};
    vector<int> large=largestDivisibleSubset(nums);
    for(int i=0;i<large.size();i++)
       cout<<large[i]<<" ";
    
    return 0;
}