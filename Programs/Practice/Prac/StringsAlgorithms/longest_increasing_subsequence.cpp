/*
L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
L(i) = 1, if no such j exists
*/
#include <bits/stdc++.h>
using namespace std;
int LIS(int arr[],int n)
{
    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<n;i++)
      {
          dp[i]=1;
          for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j]&&dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
      }
     int ans=0;
    for(int i=0;i<n;i++)
       ans=max(ans,dp[i]);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    int ans=LIS(arr,n);
    cout<<ans<<"\n";
    return 0;
}