#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s)
{

    //find the size of string
    int n = s.size();

    //if first character is 0
    if (s[0] == '0')
        return 0;

    //if size is 1 then return 1
    if (n == 1)
        return 1;
    int dp[n + 1];
    int x;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {

        x = (10 * (s[i - 2] - '0')) + s[i - 1] - '0';

        if (s[i - 1] == '0')
        {
            if (x > 26 || x == 0)
                return 0;
            else
                dp[i] = dp[i - 2];
        }
        else
        {
            dp[i] = dp[i - 1];
            if (x <= 26 && s[i - 2] != '0')
                dp[i] = dp[i] + dp[i - 2];
        }
    }
    return dp[n];
}

int main()
{
    string str = "12";
    cout << numDecodings(str);
    return 0;
}