#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) 
{
     int n=nums.size();
      int res=0;
        if(n<3)
              return res;
      sort(nums.begin(),nums.end());
        int max1=INT_MAX;
      for(int i=0;i<n-2;i++)
      {
          int low=i+1,high=n-1;
          while(low<high)
          {
              if(abs(target-(nums[i]+nums[low]+nums[high]))<max1)
              {
                  max1=abs(target-(nums[i]+nums[low]+nums[high]));
                  res=nums[i]+nums[low]+nums[high];
              }
              if(nums[i]+nums[low]+nums[high]>target)
                     high--;
              else
                  low++;
              
          }
      }
        return res;
}
int main()
{
    vector<int> nums ={-1,2,1,-4};
    int  target = 1;
    cout<<threeSumClosest(nums,target);
    return 0;
}
