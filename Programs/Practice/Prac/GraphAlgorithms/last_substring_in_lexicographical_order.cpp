#include <bits/stdc++.h>
using namespace std;

string lastSubstring(string s)
{
    int i = 0, j = 0, p = 1, k = 0;
    while (p < s.size())
    {
        if (s[p] > s[i])
        {
            i = p;
            p++;
            continue;
        }
        if (s[p] == s[i])
        {
            k = p;
            j = i;
            while (p < s.size() and s[j] == s[p] and j < k)
            {
                p++;
                j++;
            }
            if (j < k and s[j] < s[p])
            {
                i = k;
            }
            continue;
        }
        p++;
    }
    return s.substr(i);
}

int main()
{
    string s = "abab";

    cout << lastSubstring(s);

    return 0;
}