#include <bits/stdc++.h>
using namespace std;

bool checkOnesSegment(string s)
{
    int n = s.size();

    int i = 0;
    while (i < n && s[i] == '1')
    {
        i++;
    }
    while (i < n && s[i] == '0')
        i++;
    if (i == n)
        return true;
    return false;
}

int main()
{
    string s = "110";

    if (checkOnesSegment(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}