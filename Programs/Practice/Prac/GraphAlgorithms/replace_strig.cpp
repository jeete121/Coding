#include <bits/stdc++.h>
using namespace std;

string modifyString(string s)
{
    int n = s.size();
    int i = 0;
    while (i < n)
    {
        if (i == 0)
        {
            if (n == 1 && s[i] == '?')
                s[i] = 'a';
            else if (s[i] == '?')
            {
                char x = s[i + 1];
                if (x == '?')
                    s[i] = 'a';
                else
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if (('a' + j) != x)
                        {
                            s[i] = 'a' + j;
                            break;
                        }
                    }
                }
            }
        }
        else if (i == n - 1)
        {
            if (s[i] == '?')
            {
                if (s[i - 1] == '?')
                    s[i] = 'a';
                else
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if (s[i - 1] != ('a' + j))
                        {
                            s[i] = 'a' + j;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            if (s[i] == '?')
            {
                char x = s[i - 1];
                if (s[i + 1] == '?')
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if (x != ('a' + j))
                        {
                            s[i] = 'a' + j;
                            break;
                        }
                    }
                }
                else
                {
                    char x = s[i - 1];
                    char y = s[i + 1];
                    for (int j = 0; j < 26; j++)
                    {
                        if (x != ('a' + j) && y != ('a' + j))
                        {
                            s[i] = 'a' + j;
                            break;
                        }
                    }
                }
            }
        }
        i++;
    }
    return s;
}

int main()
{
    string s = "?zs";
    cout << modifyString(s);
    return 0;
}