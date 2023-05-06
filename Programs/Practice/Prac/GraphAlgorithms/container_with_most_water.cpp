#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) 
{
    int n=height.size();
    int low=0,high=n-1,res=0;
    while(low<high)
         {
            res=max(res,min(height[low],height[high])*(high-low));
            if(height[low]<height[high])
                    low++;
            else
                high--;
         }
        return res;
}
int main()
{
   vector<int> height ={4,3,2,1,4};
   cout<<maxArea(height);
   return 0;
}



