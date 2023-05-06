#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void findSubstringLen(string s)
{
    int f[26] = {0};
    for (int i = 0; i < s.size(); i++)
        f[s[i] - 'a']++;
    sort(f, f + 26);
    if (s.size() == 1)
        cout << 0 << "\n";
    else if (!ispalindrome(s))
        cout << s.size() << "\n";

    else
    {
        int i = s.size() - 1;
        while (i > 0 && s[i] == s[0])
            i--;
        if (i == 0)
            cout << 0 << "\n";
        else
            cout << i + 1 << "\n";
    }
}
int main()
{

    string s = "aba";

    findSubstringLen(s);

    return 0;
}