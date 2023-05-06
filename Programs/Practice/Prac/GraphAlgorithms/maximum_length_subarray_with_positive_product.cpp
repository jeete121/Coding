#include <bits/stdc++.h>
using namespace std;

//function to find the maximum length
//subarray with positive product
int getMaxLen(vector<int>& nums) {
        int ans=0;
        int pos=0,neg=0;
        vector<int> v;
        int index=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                if(neg%2==0)
                      ans=max(ans,pos+neg);
                else
                {
                    int start=v[0];
                    int last=v[v.size()-1];
                    ans=max(ans,max(i-1-start,last-index));
                    
                }
                neg=0;
                pos=0;
                v.clear();
                index=i+1;
            }
            else if(nums[i]<0)
            {
                v.push_back(i);
                neg++;
                

            }
            else
                  pos++;
        }
        if(v.size()!=0)
        {
                 int start=n-1-v[0];
                 int last=v[v.size()-1];
                  ans=max(ans,max(start,last-index));
        }
       if(neg%2==0)
               ans=max(ans,neg+pos);
        return ans;
}
int main()
{
    vector<int> nums ={0,1,-2,-3,-4};
    cout<<getMaxLen(nums);
    return 0;
}

