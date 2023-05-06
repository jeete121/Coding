#include <bits/stdc++.h>
using namespace std;

//function to find the kth 
//largest number in an array
int findKthLargest(int nums[], int n,int k)
{
     sort(nums,nums+n);
    for (int i = n - 1; i > 0; i--) 
      {
            k--;
            if (k == 0)
                return nums[i];
    }
    return nums[0];
}
int main()
{
    int nums[] = { 3, 2, 1, 5, 6, 4 };
    int n=sizeof(nums)/sizeof(nums[0]);
    int k = 2;
    cout<<findKthLargest(nums, n,k)<<"\n";
    return 0;
}
