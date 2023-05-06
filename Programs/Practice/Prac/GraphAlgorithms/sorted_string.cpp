#include <bits/stdc++.h>
using namespace std;

string sortedString(string s)
{
    string res = "";

    int f[26] = {0};
    for (int i = 0; i < s.size(); i++)
        f[s[i] - 'a']++;
    int p, min1 = INT_MAX;
    while (res.size() != s.size())
    {
        min1 = INT_MAX;
        for (int j = 0; j < 26; j++)
        {
            if (f[j] && f[j] < min1)
            {
                min1 = f[j];
                p = j;
            }
        }
        while (min1--)
        {
            res += p + 97;
        }
        f[p] = 0;
    }
    return res;
}
int main()
{
    string s = "aabbccdd";

    cout << sortedString(s) << "\n";

    return 0;
}