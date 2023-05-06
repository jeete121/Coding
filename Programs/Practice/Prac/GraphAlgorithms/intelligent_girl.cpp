#include <bits/stdc++.h>
using namespace std;

void intelligent(string s)
{

    int n = s.size();
    int dp[n];
    if (s[n - 1] == '2' || s[n - 1] == '4' ||
        s[n - 1] == '6' || s[n - 1] == '8')
        dp[n - 1] = 1;
    else
        dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '2' || s[i] == '4' ||
            s[i] == '6' || s[i] == '8')
            dp[i] = 1 + dp[i + 1];
        else
            dp[i] = dp[i + 1];
    }
    for (int i = 0; i < n; i++)
        cout << dp[i] << " ";
}
int main()
{
    string s = "574674546476";

    intelligent(s);

    return 0;
}