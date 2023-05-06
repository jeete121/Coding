#include <bits/stdc++.h>
using namespace std;


int removeDuplicates(int nums[],int n)
 {
        int l=0;
        int i=0;
        while(i<n)
        {
            int cnt=1;
            nums[l++]=nums[i];
            i++;
            while(i<n&&nums[i]==nums[i-1])
            {
                cnt++;
                if(cnt<3)
                     nums[l++]=nums[i];
                i++;        
            }
        }
        return l;
    }
int main()
{
    int nums[] = { 1, 4, 5, 5, 6, 7, 7, 7, 9 };
    int n=sizeof(nums)/sizeof(nums[0]);
    n = removeDuplicates(nums,n);
    for (int i = 0; i < n; i++) 
         cout<<nums[i]<<" ";
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)
