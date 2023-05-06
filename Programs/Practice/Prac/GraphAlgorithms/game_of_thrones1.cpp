#include <bits/stdc++.h>

using namespace std;

string gameOfThrones(string s)
{
    int f[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        f[s[i] - 'a']++;
    }
    int cnt = 0;
    if (s.size() <= 1)
    {
        return "YES";
    }
    for (int i = 0; i < 26; i++)
    {
        if (f[i] & 1)
        {
            cnt++;
        }
    }
    if (cnt > 1)
    {
        return "NO";
    }
    if (cnt == 1 && s.size() % 2 == 0)
    {
        return "YES";
    }
    return "YES";
}

int main()
{

    string s = "aaabbbb";

    string result = gameOfThrones(s);
    cout << result << "\n";

    return 0;
}
