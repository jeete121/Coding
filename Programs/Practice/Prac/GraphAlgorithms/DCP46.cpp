#include <bits/stdc++.h>
using namespace std;

#define SIZE 200000 + 1
long long P[SIZE * 2];
string newstring(string s)
{
    string str = "@";

    for (long long i = 0; i < s.size(); i++)
    {
        str += "#" + s.substr(i, 1);
    }

    str += "#$";
    return str;
}

string longestPalindromicSubstring(string s)
{
    string str = newstring(s);
    long long c = 0, r = 0;
    for (long long i = 1; i < str.size() - 1; i++)
    {
        long long imirror = c - (i - c);
        if (r > i)
            P[i] = min(r - i, P[imirror]);
        while (str[i + 1 + P[i]] == str[i - 1 - P[i]])
            P[i]++;
        if (i + P[i] > r)
        {
            r = i + P[i];
            c = i;
        }
    }
    long long len = 0;
    long long center = 0;
    for (long long i = 1; i < str.size() - 1; i++)
    {
        if (P[i] > len)
        {
            len = P[i];
            center = i;
        }
    }

    string ans = s.substr((center - 1 - len) / 2, len);

    return ans;
}
int main()
{
    string s = "aabcdcb";

    cout << longestPalindromicSubstring(s);

    return 0;
}