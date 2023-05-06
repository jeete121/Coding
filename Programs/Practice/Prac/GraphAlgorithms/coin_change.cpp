#include <bits/stdc++.h>
using namespace std;
int ways[100][100];

//function to no of ways 
//for the coin change
int coinChange(int coins[],int m, int sum)
{
  //if sum is 0 then 
  //their is 1 way
   if(sum==0)
       return 1;
   //if sum is negative
   if(sum<0)
      return 0;
   //if their are no coins
   if(m<0 &&sum>=1)
      return 0;
  //else calculte by include and exluding the
  //current coin
   if(ways[m][sum]==-1)
       ways[m][sum]=coinChange(coins,m-1,sum)+coinChange(coins,m,sum-coins[m]);
   return ways[m][sum];
}
int main()
{
    memset(ways,-1,sizeof(ways));
    int sum=10;
    int m=4;
    int coins[]={2,5,3,6};
    cout<<coinChange(coins, m-1,sum);
    return 0;
}
