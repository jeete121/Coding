#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

//function to find the minimum
//cost to reach from (0,0) to(n-1,n-1)
//by two ways move down or right
int findSum(int n,int i,int j,vector<vector<int>> &arr)
{
    //base case if we reach to
    //the target
    if(i==n-1&&j==n-1)
       return arr[i][j];

    //if alredy calculate
    if(dp[i][j]!=-1)
       return dp[i][j];
    
    //if in the last row
    if(i==n-1)
       {
           dp[i][j]= arr[i][j]+findSum(n,i,j+1,arr);
           return dp[i][j];
       }

    //if in the last colum
    if(j==n-1)
       {
           dp[i][j]= arr[i][j]+findSum(n,i+1,j,arr);
           return dp[i][j];
       }

    // else min of both 
    dp[i][j]= arr[i][j]+min(findSum(n,i,j+1,arr),findSum(n,i+1,j,arr));
    return dp[i][j];
}
int main()
{
  int n=5;
  vector<vector<int>> arr={{131, 673, 234 ,103, 18},
                          {201, 96, 342 ,965, 150},
                          {630, 803, 746, 422, 111},
                          {537, 699, 497, 121, 956},
                          {805, 732, 524, 37, 331}};
    
    memset(dp,-1,sizeof(dp));
    int sum=findSum(n,0,0,arr);
    cout<<sum<<"\n";
    return 0;
}
