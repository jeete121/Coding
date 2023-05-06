#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) 
{
     sort(nums.begin(),nums.end());
      int n=nums.size();
     return nums[n/2];
}

int main()
{
    vector<int> nums ={3,2,3};
    cout<<majorityElement(nums);
    return 0;
}