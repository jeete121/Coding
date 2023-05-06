#include <bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string s1, string s2)
{
    int row = s1.size(), col = s2.size();
    int dp[row + 1][col + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= row; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= col; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = row, j = col;
    string str = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            str.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] < dp[i][j - 1])
            {
                str.push_back(s1[i - 1]);
                i--;
            }
            else
            {
                str.push_back(s2[j - 1]);
                j--;
            }
        }
    }

    while (i > 0)
    {
        str.push_back(s1[i - 1]);
        i--;
    }

    while (j > 0)
    {
        str.push_back(s2[j - 1]);
        j--;
    }

    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    string str1 = "abac", str2 = "cab";

    cout << shortestCommonSupersequence(str1, str2);

    return 0;
}