#include <bits/stdc++.h>
using namespace std;

//function to find the intersection of two
//arrays
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
       //vector to hold the final result
        vector<int> res;
        int n=nums1.size();
        int m=nums2.size();

        //sort both the arays
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        set<int> st;

        //now iterate for all all elements
        while(i<n && j<m)
        {

            //if both are same then push into the set
            if(nums1[i]==nums2[j])
            {
                st.insert(nums1[i]);
                i++;
                j++;
            }
          //else if nums[i]<nums[j] then move 
          //first to the next position
            else if(nums1[i]<nums2[j])
                  i++;
          //else move second to next point
            else if(nums1[i]>nums2[j])
                   j++;
        }
    for(auto it=st.begin();it!=st.end();it++)
           res.push_back(*it);
        sort(res.begin(),res.end());
        return res;
}
int main()
{
  vector<int> nums1={1,2,2,1};
  vector<int> nums2={2,2};
  vector<int> inter=intersection(nums1,nums2);
  for(int i=0;i<inter.size();i++)
     cout<<inter[i]<<" ";
}

