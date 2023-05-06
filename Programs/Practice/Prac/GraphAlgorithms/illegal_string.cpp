#include <bits/stdc++.h>
using namespace std;

void illegibleString(int n, string s)
{
    int cntw = 0, cntv = 0;
    string str = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'w')
        {
            str += 'v';
            str += 'v';
        }
        else
            str += s[i];
    }
    string res = "";
    int i = 0;
    while (i < str.size())
    {
        if (i < str.size() - 1 &&
            str[i] == 'v' && str[i + 1] == 'v')
        {
            res += 'w';
            i += 2;
        }
        else
        {
            res += str[i];
            i++;
        }
    }
    cout << res.size() << " " << str.size() << "\n";
}
int main()
{
    int n = 5;

    string s = "avwvb";

    illegibleString(n, s);

    return 0;
}