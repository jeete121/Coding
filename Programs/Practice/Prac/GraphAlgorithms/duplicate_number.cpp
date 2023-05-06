#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) 
{
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i<nums.size()-1;i++)
               if(nums[i]==nums[i+1])
               {
                   res=nums[i];
                   break;
               }
        return res;
}
int main()
{
    vector<int> nums ={1,3,4,2,2};
    cout<<findDuplicate(nums);
    return 0;
}