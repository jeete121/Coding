#include <bits/stdc++.h>
using namespace std;


vector<int> smallerNumbersThanCurrent(vector<int>& nums)
{
    //create a dummy array
     vector<int> dummy(nums.begin(),nums.end());

     //sort the dummy array
     sort(dummy.begin(),dummy.end());
     vector<int> res;
    //itearte for all elemenst
    for(int i=0;i<nums.size();i++)
    {
        int lower=lower_bound(dummy.begin(),dummy.end(),nums[i])
                -dummy.begin();
        res.push_back(lower);
    }
        return res;
}

int main()
{
  vector<int> nums={8,1,2,2,3};
  vector<int> small=smallerNumbersThanCurrent(nums);
  for(int i=0;i<small.size();i++)
     cout<<small[i]<<" ";
  return 0;
}

//Time Complexity:O(nlog(n))