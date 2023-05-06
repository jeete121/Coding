#include <bits/stdc++.h>
using namespace std;

//function to count the number 
//of smaller elements then current element
vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
{
    vector<int> res;
     int max1=nums[0],min1=nums[0];

     //find the maximum elemeent
     //and minimum element in the array
    for(int i=0;i<nums.size();i++)
      {
          if(nums[i]>max1)
                max1=nums[i];
          else if(nums[i]<min1)
                min1=nums[i];
      }
    //create an array of size maximum element+1
    int freq[max1+1]={0};

    //count frequency of each element
    for(int i=0;i<nums.size();i++)
         freq[nums[i]]++;
    
    //count number of elements which are less than
    //the current elements
     for(int i=0;i<nums.size();i++)
     {  
         int cnt=0;
         for(int j=min1;j<nums[i];j++)
          {
             if(freq[j]>0)
                 cnt+=freq[j];
          }
        res.push_back(cnt);
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

//Time Complexity:O(n^2)
