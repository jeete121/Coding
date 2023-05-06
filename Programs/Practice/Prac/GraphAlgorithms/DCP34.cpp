#include <bits/stdc++.h>
using namespace std;

int minInsertions(string s)
{
    int n = s.length();
    vector<int> dp(n, 0);
    int i = 0, j = 0;

    for (i = 0, j = n - 1; i <= j; i++, j--)
    {
        if (s[i] != s[j])
            break;
    }

    //if already palindrome
    if (i > j)
        return 0;

    for (i = n - 2; i >= 0; i--)
    {
        int pre = 0;
        for (j = i + 1; j < n; j++)
        {
            int temp = dp[j];
            if (s[i] == s[j])
                dp[j] = pre;
            else
            {
                dp[j] = min(dp[j], dp[j - 1]) + 1;
            }
            pre = temp;
        }
    }

    return dp[n - 1];
}

int main()
{
    string s = "race";

    cout << minInsertions(s);

    return 0;
}