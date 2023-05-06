#include <bits/stdc++.h>
using namespace std;


//function to find the product
//of array except selft
vector<int> productExceptSelf(vector<int>& nums) 
{
    int n=nums.size();
    vector<int> left,right;
    left.resize(n,1);
    right.resize(n,1);

    //product of left of given position
    for(int i=1;i<n;i++)
        left[i]=left[i-1]*nums[i-1];

    //product of right of given position
    for(int i=n-2;i>=0;i--)
        right[i]=right[i+1]*nums[i+1];

    //final product except self
    for(int i=0;i<n;i++)
         nums[i]=left[i]*right[i];
     return nums;
}
int main()
{
  vector<int> arr={1,2,3,4};
  arr=productExceptSelf(arr);
  for(int i=0;i<arr.size();i++)
     cout<<arr[i]<<" ";
  return 0;
}
