#include <bits/stdc++.h>
using namespace std;

int bobAndBombs(string s)
{

    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (s[i] == 'B')
            {
                for (int j = i + 1; j <= min(i + 2, n - 1); j++)
                {
                    if (s[j] == 'W')
                    {
                        cnt++;
                        s[j] = '.';
                    }
                }
            }
        }
        else if (i == n - 1)
        {
            if (s[i] == 'B')
            {
                for (int j = i - 1; j >= max(0, i - 2); j--)
                {
                    if (s[j] == 'W')
                    {
                        cnt++;
                        s[j] = '.';
                    }
                }
            }
        }
        else
        {
            if (s[i] == 'B')
            {
                for (int j = i - 1; j >= max(0, i - 2); j--)
                {
                    if (s[j] == 'W')
                    {
                        cnt++;
                        s[j] = '.';
                    }
                }
                for (int j = i + 1; j <= min(n - 1, i + 2); j++)
                {
                    if (s[j] == 'W')
                    {
                        cnt++;
                        s[j] = '.';
                    }
                }
            }
        }
    }
    return cnt;
}
int main()
{

    string s = "WWBWWBW";

    cout << bobAndBombs(s) << "\n";

    return 0;
}