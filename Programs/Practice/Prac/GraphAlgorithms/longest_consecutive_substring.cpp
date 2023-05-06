#include <bits/stdc++.h>
using namespace std;

//function to find the length of longest
//consecutive sequence
int longestConsecutive(vector<int>& nums)
{
        sort(nums.begin(),nums.end());
        if(nums.size()==0)
               return 0;
        int cnt=1,res=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==1+nums[i-1])
            {
                cnt++;
            }
             else if(nums[i]==nums[i-1])
                    continue;
            else
            {
                res=max(res,cnt);
                cnt=1;
            }
                
        }
        res=max(res,cnt);
           return res; 
}
int main()
{
    vector<int> nums = {100,4,200,1,3,2};
    cout<<longestConsecutive(nums);
    return 0;
}

