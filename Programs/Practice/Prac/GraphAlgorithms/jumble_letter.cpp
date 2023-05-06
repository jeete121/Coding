#include <bits/stdc++.h>
using namespace std;

string jumbleLetter(string s)
{
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'y' ||
            s[i] == 'e' || s[i] == 'o' ||
            s[i] == 'i' || s[i] == 'u')
        {
            continue;
        }
        else
        {
            res += '.';
            res += s[i];
        }
    }
    return res;
}
int main()
{
    string s = "odn";

    cout << jumbleLetter(s) << "\n";

    return 0;
}