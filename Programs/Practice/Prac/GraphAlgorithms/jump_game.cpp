#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) 
{
        int n=nums.size();

        //set last as n-1 position
        int last=n-1;
        for(int i=n-1;i>=0;i--)
        {
            //if i+num[i]>=last 
            //then update last
            if(i+nums[i]>=last)
                last=i;
        }
        if(last==0)
          return true;
        return false;
}
int main()
{
    vector<int>  nums ={2,3,1,1,4};
    if(canJump(nums))
      cout<<"true\n";
    else
     cout<<"false\n";
   return 0;
}

