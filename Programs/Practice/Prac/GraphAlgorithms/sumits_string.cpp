#include <bits/stdc++.h>
using namespace std;

void distanceString(string s)
{
    int i = 0;
    int flag = 0;
    while (i < s.size() - 1)
    {
        if (s[i] == s[i + 1])
        {
            flag = 1;
            break;
        }
        if (s[i] == 'z')
        {
            if (s[i + 1] != 'a' && s[i + 1] != 'y')
            {
                flag = 1;
                break;
            }
        }
        else if (s[i + 1] == 'z')
        {
            if (s[i] != 'a' && s[i] != 'y')
            {
                flag = 1;
                break;
            }
        }
        else if (abs(s[i] - s[i + 1]) != 1)
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag)
        cout << "NO\n";
    else
        cout << "YES\n";
}
int main()
{

    string s = "bcd";

    distanceString(s);

    return 0;
}