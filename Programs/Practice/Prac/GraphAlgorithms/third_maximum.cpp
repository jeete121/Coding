#include <bits/stdc++.h>
using namespace std;

int thirdMax(vector<int>& nums) 
{
    int max=INT_MIN,max1=INT_MIN,max2=INT_MIN;
        int n=nums.size();
        
     for(int i=0;i<nums.size();i++)
     {
         if(max<nums[i])
              max=nums[i];
     }
    for(int i=0;i<n;i++)
    {
        if(max1<nums[i]&& nums[i]!=max)
            max1=nums[i];
    }
 for(int i=0;i<n;i++)
    {
        if(max2<nums[i]&& nums[i]!=max&&nums[i]!=max1)
            max2=nums[i];
    }
    if(n<=2 ||(max1==INT_MIN))
      return max;
    else
    {
        int flag=0;
       for(int i=0;i<n;i++)
           if(nums[i]==max2)
           {
               flag=1;
               break;
           }
      if(flag==0)
           return max;
      else
          return max2;
    }
}
int main()
{
    vector<int> nums ={3,2,1};
    cout<<thirdMax(nums);
    return 0;
}