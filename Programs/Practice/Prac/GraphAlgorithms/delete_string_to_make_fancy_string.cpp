#include <bits/stdc++.h>
using namespace std;

string makeFancyString(string s)
{

    string res = "";
    res += s[0];
    int cnt = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            cnt++;
        else
            cnt = 1;
        if (cnt < 3)
            res += s[i];
    }

    return res;
}
int main()
{
    string s = "aaabaaaa";

    cout << makeFancyString(s) << "\n";

    return 0;
}