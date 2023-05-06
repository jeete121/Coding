#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "07:05:45PM";
    int i;
    int h1 = (int)s[1] - '0';
    int h2 = (int)s[0] - '0';
    int hh = (h2 * 10 + h1);
    if (s[8] == 'A')
    {
        if (hh == 12)
        {
            cout << "00";
            for (int i = 2; i <= 7; i++)
                cout << s[i];
        }
        else
            for (i = 0; i <= 7; i++)
                cout << s[i];
    }
    if (s[8] == 'P')
    {
        if (hh == 12)
        {
            cout << "12";
            for (int i = 2; i <= 7; i++)
                cout << s[i];
        }
        else
        {
            hh = hh + 12;
            cout << hh;
            for (int i = 2; i <= 7; i++)
                cout << s[i];
        }
    }
    return 0;
}
