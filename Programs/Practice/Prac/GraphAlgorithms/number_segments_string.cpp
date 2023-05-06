#include <bits/stdc++.h>
using namespace std;

int countSegments(string s)
{
    int cnt = 0;
    if (s.size() == 1)
        if (s[0] != ' ')
            return 1;
    for (int i = 1; i < s.size(); i++)
    {

        if ((s[i] == ' ' && s[i - 1] != ' '))
            cnt++;
        if (i == s.size() - 1 && s[i] != ' ')
            cnt++;
    }
    return cnt;
}

int main()
{
    string s = "Hello, my name is John";

    cout << countSegments(s);

    return 0;
}