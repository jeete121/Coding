#include <bits/stdc++.h>
using namespace std;


vector<int> minSubsequence(vector<int>& nums)
{
    //sort the array in decreasing order
       sort(nums.begin(),nums.end(),greater<int>());
        int sum=0;

    //find the sum of array elements
    for(int i=0;i<nums.size();i++)
        {
          sum+=nums[i];   
        }
     int sum1=0;
        vector<int> res;
      for(int i=0;i<nums.size();i++)
      {
          sum1+=nums[i];
          res.push_back(nums[i]);
          if(sum1>sum/2)
          {
             break;  
          }
      }
        return res;
}
int main()
{
    vector<int> nums ={4,3,10,9,8};
    vector<int > arr=minSubsequence(nums);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    return 0;
}
