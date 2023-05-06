#include <bits/stdc++.h>
using namespace std;


void rotate(int nums[], int n, int k)
{
    for (int i = 0; i < k; i++) 
     {
        int tmp = nums[n - 1];
            for (int j = n - 1; j > 0; j--) 
            {
                nums[j] = nums[j - 1];
            }
            nums[0] = tmp;
    }
}

int main()
{
     int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
     int k = 3;
     int n=sizeof(nums)/sizeof(nums[0]);
     rotate(nums, n,k);
     for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
      return 0;
}


