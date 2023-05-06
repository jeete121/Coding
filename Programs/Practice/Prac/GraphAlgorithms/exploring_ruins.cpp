#include <bits/stdc++.h>
using namespace std;

string exploringRuins(string s)
{
    int n = s.size();
    if (s.size() == 1)
    {
        if (s[0] == '?')
            s[0] = 'a';
        return s;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (s[i] == '?' && s[i + 1] == '?')
                    s[i] = 'a';
                else if (s[i] == '?' && s[i + 1] == 'b')
                    s[i] = 'a';
                else if (s[i] == '?' && s[i + 1] == 'a')
                    s[i] = 'b';
            }
            else if (i == n - 1)
            {
                if (s[i] == '?')
                {
                    if (s[i - 1] == 'a')
                        s[i] = 'b';
                    else
                        s[i] = 'a';
                }
            }
            else
            {
                if (s[i] == '?')
                {
                    if (s[i - 1] == 'a')
                        s[i] = 'b';
                    else if (s[i - 1] == 'b' && s[i + 1] == 'a')
                        s[i] = 'b';
                    else
                        s[i] = 'a';
                }
            }
        }
        return s;
    }
}
int main()
{

    string s = "?ba??b";

    cout << exploringRuins(s) << "\n";

    return 0;
}