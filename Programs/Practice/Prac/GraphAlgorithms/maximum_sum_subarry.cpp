#include <bits/stdc++.h>
using namespace std;


//function to find the maximum 
//subarray sum 
int maxSubArray(vector<int>& nums) 
{
    int max_sum=nums[0];
    int sum=nums[0];
    for(int i=1;i<nums.size();i++)
        {
          //if sum becomes zero or negative then 
          //make it as 0
          if(sum<=0)
              sum=0;
          //add current element into sum
           sum+=nums[i];

           //update the max_sum
           max_sum=max(sum,max_sum);
       }
    //return the max sum
  return max_sum;
}
int main()
{
   vector<int> nums ={-2,1,-3,4,-1,2,1,-5,4};
   cout<<maxSubArray(nums);
   return 0;
}

