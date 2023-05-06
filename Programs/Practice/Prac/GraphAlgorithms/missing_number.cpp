#include <bits/stdc++.h>
using namespace std;

//find the missing number in the array
//all number are from 0 to n-1
int missingNumber(vector<int>& nums) 
{
    int n=nums.size();
    int res=0;
    for(int i=1;i<=n;i++)
         res=res^i;
    for(int i=0;i<n;i++)
       res^=nums[i];
   return res;
}
int main()
{
  vector<int> nums={3,0,1};
  int missing=missingNumber(nums);
  cout<<missing<<"\n";
  return 0;
}