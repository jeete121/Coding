#include <bits/stdc++.h>
using namespace std;

bool isvowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int adamantVowels(string s)
{
    int n = s.size();
    string str = s;
    int cnt = 0;
    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++)
    {
        if (s[i] == str[i] && isvowel(s[i]) == true)
            cnt++;
    }
    return cnt;
}
int main()
{
    string s = "notion";

    cout << adamantVowels(s) << "\n";

    return 0;
}