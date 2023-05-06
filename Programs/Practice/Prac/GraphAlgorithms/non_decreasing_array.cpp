#include <bits/stdc++.h>
using namespace std;

bool checkPossibility(vector<int>& nums)
{
        int n=nums.size(),cnt=0;
        for (int i = 0; i <n-1 && cnt<=1;i++) 
        {
            if (nums[i] > nums[i + 1]) 
            {
                if (i > 0)
                {
                    if (nums[i - 1] <= nums[i + 1])
                        nums[i] = nums[i - 1];  
                    else           
                        nums[i + 1] = nums[i]; 
                }
                ++cnt;
            }
        }
        return cnt<=1;
}

int main()
{
     vector<int> nums ={4,2,3};
     if(checkPossibility(nums))
       cout<<"true";
    else
      cout<<"false";

    return  0;
}