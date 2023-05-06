#include <bits/stdc++.h>
using namespace std;


string decodeAtIndex(string S, int K)
{
    long long int n = S.size();
    long long int len = 0;
    if (K == 1)
    {
        if (isalpha(S[0]))
            return string(1, S[0]);
        else
            return "";
    }
    for (long long int i = 0; i < n; i++)
    {
        if (isdigit(S[i]))
            len = len * (S[i] - '0');
        else
            len++;
    }
    for (long long int i = n - 1; i >= 0; i--)
    {
        K %= len;
        if (K == 0 && isalpha(S[i]))
            return string(1, S[i]);
        else if (isdigit(S[i]))
            len = len / (S[i] - '0');
        else
            len--;
    }
    return "";
}

int main()
{
    string S = "ha22";
    int K = 5;
    cout << decodeAtIndex(S, K);
    return 0;
}