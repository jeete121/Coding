#include <bits/stdc++.h>
using namespace std;

//function to check if length of
//the number is even or not
bool isEven(int a)
{
        int cnt=0;
        while(a)
        {
            cnt++;
            a/=10;
        }
        if(cnt%2==0)
              return true;
        return false;
}
int findNumbers(vector<int>& nums) 
{
    int cnt=0;
    for(int i=0;i<nums.size();i++)
      {
         
         if(isEven(nums[i]))
             {
              cnt++;
             }  
      }
   return cnt;
}
int main()
{
    vector<int> nums ={12,345,2,6,7896};
    cout<<findNumbers(nums);
    return 0;
}
