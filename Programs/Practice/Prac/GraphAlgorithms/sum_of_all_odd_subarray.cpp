#include <bits/stdc++.h>
using namespace std;


//function to find all the subarray of
//odd length
int sumOddLengthSubarrays(vector<int>& arr) 
{
    int n=arr.size();
    int ans=0;
    for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++) 
            {
                sum+=arr[j];
                if((j-i)%2==0)
                      ans+=sum;
            }
        }
        return ans;
}
int main()
{
   vector<int> arr = {1,4,2,5,3};
   cout<<sumOddLengthSubarrays(arr);
   return 0;
}
