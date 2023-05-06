#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2)
{
    int m = word1.size(), n = word2.size();

    //create a 2D array of size (m+1)*(n+1)
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            //if first is empty
            if (i == 0)
                dp[i][j] = j;

            //if second is empty
            else if (j == 0)
                dp[i][j] = i;
            //if both are same
            else if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            //else min of insert,delete and replace
            else
                dp[i][j] = 1 + min(dp[i - 1][j],
                                   min(dp[i][j - 1],
                                       dp[i - 1][j - 1]));
        }
    }
    return dp[m][n];
}
int main()
{
    string word1 = "kitten", word2 = "sitting";
    cout << minDistance(word1, word2);
    return 0;
}
