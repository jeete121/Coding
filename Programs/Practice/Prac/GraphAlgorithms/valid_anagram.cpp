#include <bits/stdc++.h>
using namespace std;

//function to check if two
//strings are anagram or not
bool isAnagram(string str1, string str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 != len2)
        return false;
    unordered_map<char, int> ump;
    for (int i = 0; i < len1; i++)
    {
        ump[str1[i]]++;
    }
    for (int i = 0; i < len2; i++)
    {
        if (ump[str2[i]] == 0)
            return false;
        else
            ump[str2[i]]--;
    }
    for (auto it = ump.begin(); it != ump.end(); it++)
    {
        if (it->second > 0)
            return false;
    }
    return true;
}

int main()
{
    string s = "anagram", t = "nagaram";
    if (isAnagram(s, t))
        cout << "true";
    else
        cout << "false";

    return 0;
}
