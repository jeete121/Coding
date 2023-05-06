#include <bits/stdc++.h>
using namespace std;

//function to find the intersection of
//two arrays
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
{
    int n=nums1.size();
    int m=nums2.size();

    //sort both the arrays
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int i=0,j=0;
    vector<int> res;

    //ietare till the end of the arrays
    while(i<n && j<m)
        {

            //if both are sam then
            //push into the result
            if(nums1[i]==nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }

            //if fisrt is smaller then move first 
            //to next position
            else if(nums1[i]<nums2[j])
                  i++;

             //else move second to the next position
            else if(nums1[i]>nums2[j])
                   j++;
        }
        return res;
}
int main()
{
  vector<int> nums1={1,2,2,1};
  vector<int> nums2={2,2};
  vector<int> inter=intersect(nums1,nums2);
  for(int i=0;i<inter.size();i++)
     cout<<inter[i]<<" ";
}
