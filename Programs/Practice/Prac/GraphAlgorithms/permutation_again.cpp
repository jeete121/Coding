#include <bits/stdc++.h>
using namespace std;
long long permutationAgain(long long n)
{

    long long dp[n + 1];
    dp[1] = 1;
    dp[2] = 1;
    for (long long i = 3; i <= n; i++)
    {
        if (i & 1)
            dp[i] = i - 1 + dp[i - 1];
        else
            dp[i] = i + dp[i - 1];
    }
    return dp[n];
}
int main()
{

    long long n = 3;

    cout << permutationAgain(n) << "\n";

    return 0;
}
