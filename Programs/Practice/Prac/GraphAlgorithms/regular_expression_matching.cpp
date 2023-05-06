#include <bits/stdc++.h>
using namespace std;

bool isMatch(string a, string b)
{
    int n = a.size(), m = b.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                dp[i][j] = (j == 0);
                if (j && b[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2];
            }
            else
            {
                //one character match
                if (j && b[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                //if 0 or more character match
                else if (j && b[j - 1] == '*')
                {
                    //if 0 or more character match
                    if (b[j - 2] == '.')
                    {
                        dp[i][j] = (dp[i - 1][j] ||
                                    dp[i][j - 2]);
                    }
                    else
                    {

                        if (a[i - 1] == b[j - 2])
                        {
                            dp[i][j] = (dp[i - 1][j] ||
                                        dp[i][j - 2]);
                        }
                        else
                        {
                            dp[i][j] = dp[i][j - 2];
                        }
                    }
                }
                else if (i && j)
                {
                    dp[i][j] = (a[i - 1] == b[j - 1] &&
                                dp[i - 1][j - 1]);
                }
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s = "aa", p = "a*";

    if (isMatch(s, p))
        cout << "true";
    else
        cout << "false";

    return 0;
}