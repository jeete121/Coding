#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> ump;
    for (int i = 0; i < s.size(); i++)
    {
        if (ump.find(s[i]) != ump.end())
        {
            if (ump[s[i]] != t[i])
                return false;
        }
        ump[s[i]] = t[i];
    }
    ump.clear();
    for (int i = 0; i < t.size(); i++)
    {
        if (ump.find(t[i]) != ump.end())
        {
            if (ump[t[i]] != s[i])
                return false;
        }
        ump[t[i]] = s[i];
    }
    return true;
}

int main()
{
    string s = "egg", t = "add";

    if (isIsomorphic(s, t))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}