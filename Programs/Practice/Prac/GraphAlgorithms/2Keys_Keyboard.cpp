#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int minStepsHelper(int Acount, int copyCount, int target)
{
    //If the A's count becomes same as the number of A's we need,
    // We return 1 because this was one way of copying and pasting
    if (Acount == target)
        return 1;

    //If the A's count goes beyond the number of A's we need,
    //we can return a large no. as its not a correct way of
    // copy pasting
    if (Acount > target)
        return 10e6;

    if (dp[Acount][copyCount] != -1) //DP check
        return dp[Acount][copyCount];

    //1. to paste whatever was copied previously
    // (Add +1 because this counts as one step, we're only pasting )
    //2.OR to copy all the A's and paste it (this counts as 2 steps,
    //copying and pasting, so we add +2) .We need min of these two
    //options
    dp[Acount][copyCount] = min(minStepsHelper(Acount + copyCount, copyCount, target) + 1,
                                minStepsHelper(Acount * 2, Acount, target) + 2);
    return dp[Acount][copyCount];
}
int minSteps(int n)
{

    if (n == 1)
        return 0;
    memset(dp, -1, sizeof(dp));
    return minStepsHelper(1, 1, n);
}

int main()
{
    int n = 3;

    cout << minSteps(n);

    return 0;
}