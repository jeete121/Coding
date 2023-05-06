#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
//function to find the maximum profit 
//we can get after putting all elements whose
//capacity of weight is less then or equal to capacity
int knapSackDP(vector<int> profit,vector<int> weight,int capacity,int n)
{

    //base case if their is no elements
    //or capacity is zero then return 0
    if(n==-1||capacity==0)
       return 0;

   //if already calculated then return 
    if(dp[n][capacity]!=-1)
        return dp[n][capacity];
    //if the weight of current element is 
    //greater than the value of the remaining 
    //capacity then ignore the current element
    if(weight[n]>capacity)
       dp[n][capacity]=knapSackDP(profit,weight,capacity,n-1);

    //else the answer will we max after including
    //the current element or by excluding the current element
    else
      dp[n][capacity]=max(knapSackDP(profit,weight,capacity,n-1),
        profit[n]+knapSackDP(profit,weight,capacity-weight[n],n-1));
    return dp[n][capacity];
}
int main()
{
    vector<int> profit={3,4,5,2,6,7};
    vector<int> weight={1,3,4,2,5,8};
    int capacity=13;
    memset(dp,-1,sizeof(dp));
    cout<<knapSackDP(profit,weight,capacity,profit.size()-1);

    return 0;
    
}

