#include <bits/stdc++.h>
using namespace std;

int kPalindrome(string str1, string str2, int m, int n)
{
    vector<vector<int>> dp;

    for (int i = 0; i <= m; ++i)
    {
        vector<int> x;
        for (unsigned j = 0; j <= n; ++j)
            x.push_back(0);
        dp.push_back(x);
    }

    //fill the table using a bottom-up method
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {

            // if the first string is empty,
            if (i == 0)
                dp[i][j] = j;

            // if the second string is empty
            else if (j == 0)
                dp[i][j] = i;

            // if the last characters match,
            //then we can move past them to the
            //remaining substring
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // if the last characters dont match,
            // remove them and find the minimum
            // by removing characters from each string
            // (both forward and the reverse)
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

bool isKPalindrome(string str, int k)
{

    int len = str.length();
    string reverseStr = str;

    reverse(reverseStr.begin(), reverseStr.end());
    int result = kPalindrome(str, reverseStr, len, len);

    if (result <= k * 2)
        return true;
    return false;
}

int main()
{

    int k = 2;
    string str = "waterrfetawx";
    if (isKPalindrome(str, k))
        cout << "true";
    else
        cout << "false";

    return 0;
}