#include <bits/stdc++.h>
using namespace std;

int atMostNGivenDigitSet(vector<string> &digits, int n)
{
    string num = to_string(n);
    int K = num.length();
    vector<int> dp(K + 1);
    dp[K] = 1;
    for (int i = K - 1; i >= 0; i--)
    {
        for (string d : digits)
        {
            if (d[0] < num[i])
                dp[i] += pow(digits.size(), K - i - 1);
            else if (d[0] == num[i])
                dp[i] += dp[i + 1];
        }
    }
    for (int i = 1; i < K; i++)
        dp[0] += pow(digits.size(), i);
    return dp[0];
}

int main()
{
    vector<string> digits = {"1", "3", "5", "7"};
    int n = 100;

    cout << atMostNGivenDigitSet(digits,n);

    return 0;
}