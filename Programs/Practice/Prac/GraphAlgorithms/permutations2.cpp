#include <bits/stdc++.h>
using namespace std;

set<vector<int>> st1;
vector<vector<int>> ans;
    void generate(int l,int r,vector<int> &nums)
    {
        if(l==r)
        {
            if(st1.find(nums)==st1.end())
            {
                ans.push_back(nums);
                st1.insert(nums);
            }
        }
        else
        {
            for(int i=l;i<=r;i++)
            {
                swap(nums[l],nums[i]);
                generate(l+1,r,nums);
                swap(nums[l],nums[i]);
            }
        }
    }
vector<vector<int>> permuteUnique(vector<int>& nums) 
{
        int n=nums.size();
        ans.clear();
        st1.clear();
        generate(0,n-1,nums);
        return ans;
}

int main()
{
    vector<int> nums={1,1,2};
    vector<vector<int>> res=permuteUnique(nums);

    cout<<"[";
    for(int i=0;i<res.size();i++)
     {
         cout<<"[";
         for(int j=0;j<res[i].size();j++)
           {
               cout<<res[i][j];
               if(j!=res[i].size()-1)
                  cout<<",";

           }
           cout<<"]";
           if(i!=res.size()-1)
             cout<<",";
     }
    cout<<"]";

}