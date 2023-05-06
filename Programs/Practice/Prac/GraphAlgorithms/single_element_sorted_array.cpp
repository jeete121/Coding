#include <bits/stdc++.h>
using namespace std;


int singleNonDuplicate(vector<int>& nums) 
{
     int res=0;
      for(int i=0;i<nums.size();i++)
            res^=nums[i];
     return res;
}

int main()
{
    vector<int> nums={3,3,7,7,10,11,11};
    cout<<singleNonDuplicate(nums);
    return 0;
}