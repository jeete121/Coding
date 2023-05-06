#include <bits/stdc++.h>
using namespace std;

//function to count number of 
//steps to reduce a number to 0
int numberOfSteps (int num) 
{
    int dp[num+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=num;i++)
        {
            if(i&1)
                dp[i]=1+dp[i-1];
            else
                dp[i]=1+dp[i/2];
        }
    return dp[num];
 }
int main()
{
    int n=14;
    cout<<numberOfSteps(n);
    return 0;
}


