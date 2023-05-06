#include <bits/stdc++.h>
using namespace std;

bool checkRecord(string s)
{
    int cnt = 0, n = s.size();
    for (int i = 0; i < n; i++)
        if (s[i] == 'A')
            cnt++;
    if (cnt > 1)
        return false;
    int i = 0;
    while (i < n && s[i] != 'L')
        i++;
    while (i < n)
    {
        if (s[i] == 'L')
        {
            int cnt = 0;
            while (i < n && s[i] == 'L')
            {
                cnt++;
                i++;
            }
            i++;
            if (cnt > 2)
                return false;
        }
        else
            i++;
    }
    return true;
}

int main()
{
    string str = "PPALLP";
    if (checkRecord(str))
        cout << "true";
    else
        cout << "false";

    return 0;
}