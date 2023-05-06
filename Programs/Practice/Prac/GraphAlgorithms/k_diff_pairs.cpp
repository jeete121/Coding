#include <bits/stdc++.h>
using namespace std;


int findPairs(vector<int>& nums, int k) 
{
        set<pair<int,int>> st;
        set<int> st1;
        for(int i=0;i<nums.size();i++)
               st1.insert(nums[i]);
        sort(nums.begin(),nums.end());
        if(k>0)
        {
        for(int i=0;i<nums.size();i++)
        {
            if(st1.find(abs(k)+nums[i])!=st1.end())
                   st.insert({nums[i],abs(k)+nums[i]});
        }
        return st.size();
        }
        else if(k==0)
        {
            map<int,int> mp;
            for(int i=0;i<nums.size();i++)
                   mp[nums[i]]++;
           int ans=0;
            for(auto it=mp.begin();it!=mp.end();it++)
            {
                if(it->second>1)
                      ans+=1;
            }
            return ans;
        }
        else
             return 0;
}
int main()
{
    vector<int> nums ={3,1,4,1,5};
    int  k = 2;
    cout<<findPairs(nums,k);
    return 0;
}

