#include <bits/stdc++.h>
using namespace std;

void battleOfWords(string s, string s1)
{
    int i = 0;
    int n = s.size(), m = s1.size();
    int f[26] = {0};
    int f1[26] = {0};
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            f[s[i] - 'a']++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (s1[i] != ' ')
        {
            f1[s1[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (f[i] > f1[i])
        {
            f[i] = f[i] - f1[i];
            f1[i] = 0;
        }
        else
        {
            f1[i] = f1[i] - f[i];
            f[i] = 0;
        }
    }
    sort(f, f + 26);
    sort(f1, f1 + 26);

    if (f[25] == 0 && f1[25] != 0)
        cout << "You lose some.\n";
    else if (f1[25] == 0 && f[25] != 0)
        cout << "You win some.\n";
    else
        cout << "You draw some.\n";
}
int main()
{
    string s = "i will win";
    string s1 = "will i";

    battleOfWords(s, s1);

    return 0;
}