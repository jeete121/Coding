#include <bits/stdc++.h>
using namespace std;

void mirror(string s)
{
    int flag = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '0' && s[i] != '1' && s[i] != '8')
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        cout << "NO\n";
    else
    {
        int i = 0;
        while (i < s.size() / 2)
        {
            if (s[i] != s[s.size() - i - 1])
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
}
int main()
{

    string s = "101";

    mirror(s);

    return 0;
}
