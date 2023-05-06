#include <bits/stdc++.h>
using namespace std;

//function to merge two sorted array
 void merge(vector<int> &nums1, int n, vector<int> &nums2, int m) 
 {
    int i = nums1.size() - 1;
     n = n - 1;
     m = m - 1;
        // iterate till n>=0 and m>=0
    while (n >= 0 && m >= 0) 
    {
            // set element at last of array
            if (nums1[n] > nums2[m]) {
                nums1[i--] = nums1[n];
                n--;
            } else {
                nums1[i--] = nums2[m];
                m--;
            }
     }
     //if first array is left
     while (n >= 0) {
            nums1[i--] = nums1[n];
            n--;
        }

     //if second array is left
        while (m >= 0) {
            nums1[i--] = nums2[m];
            m--;
        }

 }

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    int n = 3;
    vector<int> nums2= { 2,5,6 };
    int m = 3;
    merge(nums1, n, nums2, m);

    //print the final array
    for(int i=0;i<nums1.size();i++)
        cout<<nums1[i]<<" ";
    return 0;
}
