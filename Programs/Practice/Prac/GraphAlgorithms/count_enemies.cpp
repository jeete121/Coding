#include <bits/stdc++.h>
using namespace std;

void countEnemies(string s)
{
    int n = s.size();
    if (s.size() == 1)
    {
        if (s[0] == 'O')
            cout << "1\n";
        else
            cout << "0\n";
    }
    else
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'X')
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (s[j] == '*')
                        break;
                    else if (s[j] == 'O')
                        s[j] = '.';
                }
                for (int j = i - 1; j >= 0; j--)
                {
                    if (s[j] == '*')
                        break;
                    else if (s[j] == 'O')
                        s[j] = '.';
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'O')
                cnt++;
        }
        cout << cnt << "\n";
    }
}
int main()
{

    string s = "X*OO*XX";

    countEnemies(s);

    return 0;
}