#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    int f1[26] = {0};
    int f2[26] = {0};
    int n = ransomNote.size(), m = magazine.size();
    if (n > m)
        return false;
    for (int i = 0; i < n; i++)
        f1[ransomNote[i] - 'a']++;
    for (int i = 0; i < m; i++)
        f2[magazine[i] - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        if (f2[i] < f1[i])
            return false;
    }
    return true;
}

int main()
{
    string ransomNote = "aa", magazine = "aab";
    if (canConstruct(ransomNote, magazine))
        cout << "true";
    else
        cout << "false";

    return 0;
}