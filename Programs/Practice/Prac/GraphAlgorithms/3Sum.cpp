#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
        int n=nums.size();
        vector<vector<int>> res;
        if(n<3)
               return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            int low=i+1;
           int  high=n-1;
            if(i>0 && nums[i]==nums[i-1])
                   continue;
            while(low<high)
            {
         if(nums[low]+nums[high]+nums[i]==0)
               {
                   vector<int> x;
                   x.push_back(nums[i]);
                   x.push_back(nums[low]);
                   x.push_back(nums[high]);
                   res.push_back(x);
                   low++;
                   high--;
                   while(low<high &&nums[high]==nums[high+1])
                          high--;
                   while(low<high && nums[low]==nums[low-1])
                          low++;
               }
             else if(nums[low]+nums[high]+nums[i]>0)
                     high--;
             else
                 low++;
            }
        }
        return res;
}
int main()
{
   vector<int> nums ={-1,0,1,2,-1,-4};
   vector<vector<int>> sum=threeSum(nums);
   cout<<"[";
   for(int i=0;i<sum.size();i++)
     {
         cout<<"[";
         for(int j=0;j<sum[i].size();j++)
          {
              cout<<sum[i][j];
              if(j!=sum[i].size()-1)
                 cout<<",";
                
          }
        if(i!=sum.size()-1)
           cout<<"],";
        else
         cout<<"]";
        
     }
    cout<<"]";
  return 0;
    
}
