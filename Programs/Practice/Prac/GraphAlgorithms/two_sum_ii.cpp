#include <bits/stdc++.h>
using namespace std;
// two sum index equals target using two pointer approach
vector<int>  twoSum(int nums[],int n, int target) 
{

       vector<int > v;
        int low = 0;
        int high=n-1;
        // iterate till low<=high
        while (low <= high) 
        {
            // if sum equals
            if ((nums[low] + nums[high]) == target)
                {
                    v.push_back(low+1);
                    v.push_back(high+1);
                    break;
                }
                // move pointer
            else if ((nums[low] + nums[high]) > target) {
                high--;
            } else {
                low++;
            }
        }
        return v;

}

int main()
{
    int arr[] = { 2, 7, 11, 15 };
    int target = 9;
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> res= twoSum(arr,n, target);
    for(int i=0;i<res.size();i++)
       cout<<res[i]<<" ";
    return 0;
}


