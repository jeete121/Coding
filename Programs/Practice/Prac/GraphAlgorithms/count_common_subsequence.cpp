#include <bits/stdc++.h>
using namespace std;

int commonSubsequence(string str1, string str2)
{
    int n = str1.size(), m = str2.size();

    int dp[n + 1][m + 1];

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string str1 = "abcd";
    string str2 = "abd";

    cout << commonSubsequence(str1, str2);

    return 0;
}