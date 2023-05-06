#include <bits/stdc++.h>
using namespace std;

void saveVanshuAndAshu(int n, string s)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'v' && s[i + 1] == 'v')
        {
            flag = 1;
            break;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            cnt++;
    }
    if (cnt == 1)
        flag = 1;
    if (flag == 1)
        cout << "No\n";
    else if (n == 1 && s[0] == 'v')
        cout << "Yes\n";
    else
    {
        int f = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (s[i] == 'a' && s[i + 1] == 'a')
                {
                    s[i] = 'v';
                    f = 1;
                    break;
                }
            }
            else if (i == n - 1)
            {
                if (s[i] == 'a' && s[i - 1] == 'a')
                {
                    s[i] = 'v';
                    f = 1;
                    break;
                }
            }
            else
            {
                if (s[i] == 'a' && s[i - 1] == 'a' && s[i + 1] == 'a')
                {
                    s[i] = 'v';
                    f = 1;
                    break;
                }
            }
        }
        if (f == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
int main()
{
    int n = 5;

    string s = "vaaav";

    saveVanshuAndAshu(n, s);

    return 0;
}