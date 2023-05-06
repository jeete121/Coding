#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
     int j=0;
     int n=nums.size();
     for(int i=0;i<n;i++)
       {
          if(nums[i]!=val)
               {
                 nums[j++]=nums[i];
               }
       }
   return j;
}
int main()
{
    vector<int> nums ={3,2,2,3};
    int val = 3;
    int index=removeElement(nums,val);
    for(int i=0;i<index;i++)
       cout<<nums[i]<<" ";
    return 0;
}

