#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string str)
{
    int j = 0;
    unordered_map<char, string> ump;
    int k = 0;
    int cnt = 0;
    while (k < str.size() && str[k] != ' ')
    {
        k++;
        if (str[k] == ' ')
        {
            k++;
            cnt++;
        }
        if (k == str.size())
            cnt++;
    }
    if (cnt != pattern.size())
        return false;
    for (int i = 0; i < pattern.size(); i++)
    {
        char temp = pattern[i];
        string x = "";
        while (j < str.size() && str[j] != ' ')
        {
            x += str[j];
            j++;
        }
        j++;
        if (ump.find(temp) == ump.end())
            ump[temp] = x;
        else
        {
            if (ump[temp] != x)
                return false;
        }
    }
    set<string> st1;
    set<char> st2;
    for (auto it = ump.begin(); it != ump.end(); it++)
    {
        st1.insert(it->second);
        st2.insert(it->first);
    }
    if (st1.size() == ump.size())
        return true;
    return false;
}

int main()
{
    string pattern = "abba", s = "dog cat cat dog";

    if (wordPattern(pattern, s))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}