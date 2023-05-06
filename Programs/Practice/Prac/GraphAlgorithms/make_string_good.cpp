#include <bits/stdc++.h>
using namespace std;

string makeGood(string s)
{
    string str = "";
    while (true)
    {
        int n = s.size();
        str = "";
        int i = 0;
        int flag = 0;
        while (i < n)
        {
            if (i < n - 1)
            {
                if (s[i] >= 'a' && s[i] <= 'z')
                {
                    char y = s[i + 1];
                    if (y >= 'A' && y <= 'Z')
                    {
                        if (y + 32 == s[i])
                        {
                            flag = 1;
                            i += 2;
                        }
                        else
                        {
                            str += s[i];
                            i++;
                        }
                    }
                    else
                    {
                        str += s[i];
                        i++;
                    }
                }
                else if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    char y = s[i + 1];
                    if (y >= 'a' && y <= 'z')
                    {
                        if (y - 32 == s[i])
                        {
                            i += 2;
                            flag = 1;
                        }
                        else
                        {
                            str += s[i];
                            i++;
                        }
                    }
                    else
                    {
                        str += s[i];
                        i++;
                    }
                }
            }
            else
            {
                str += s[i];
                i++;
            }
        }
        s = str;
        if (flag == 0)
            break;
    }
    return str;
}

int main()
{
    string str = "aDdCD";
    cout << makeGood(str);
    return 0;
}