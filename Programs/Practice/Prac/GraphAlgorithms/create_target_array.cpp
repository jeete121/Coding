#include <bits/stdc++.h>
using namespace std;

//function to create the array 
vector<int> createTargetArray(vector<int>& nums, 
    vector<int>& index) 
{
        vector<int> target;
        int n=nums.size();
        if(n==0)
               return target;
        for(int i=0;i<n;i++)
               target.insert(target.begin()+index[i],nums[i]);
        return target;
}
int main()
{
   vector<int> nums {0,1,2,3,4};
   vector<int> index ={0,1,2,2,1};
   vector<int> newArray=createTargetArray(nums,index);
   for(int i=0;i<newArray.size();i++)
      cout<<newArray[i]<<" ";
   return 0;
}

