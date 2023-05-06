#include <bits/stdc++.h>
using namespace std;


vector<int> shuffle(vector<int>& nums, int n) 
{
        vector<int> res;
        for(int i=0;i<n;i++)
        {
                 res.push_back(nums[i]);
                res.push_back(nums[n+i]);
        }
        return res;
}
int main()
{
  vector<int> nums ={2,5,1,3,4,7};
  int n = 3;
  vector<int> shuf=shuffle(nums,n);
  for(int i=0;i<shuf.size();i++)
     cout<<shuf[i]<<" ";
  return 0;
}

