#include <bits/stdc++.h>
using namespace std;

void alienLanguage(string s, string p)
{
    int f[26] = {0}, f1[26] = {0};
    int n = s.size(), m = p.size();
    for (int i = 0; i < n; i++)
        f[s[i] - 'a']++;
    for (int i = 0; i < m; i++)
        f1[p[i] - 'a']++;
    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        if (f[i] > 0 && f1[i] > 0)
        {
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}
int main()
{

    string s = "hackerearth", p = "hacker";

    alienLanguage(s, p);

    return 0;
}