#include <bits/stdc++.h>
using namespace std;

int marsExploration(string s)
{
    int i = 0, cnt = 0, n = s.size();
    while (i < n)
    {
        if (s[i] == 'S' && s[i + 1] == 'O' && s[i + 2] == 'S')
            i += 3;
        else if (s[i] == 'S' && s[i + 1] == 'O' && s[i + 2] != 'S')
        {
            i += 3;
            cnt++;
        }
        else if (s[i] == 'S' && s[i + 1] != 'O' && s[i + 2] == 'S')
        {
            cnt++;
            i += 3;
        }
        else if (s[i] != 'S' && s[i + 1] == 'O' && s[i + 2] == 'S')
        {
            cnt++;
            i += 3;
        }

        else if (s[i] == 'S' && s[i + 1] != 'O' && s[i + 2] != 'S')
        {
            cnt += 2;
            i += 3;
        }

        else if (s[i] != 'S' && s[i + 1] == 'O' && s[i + 2] != 'S')
        {
            cnt += 2;
            i += 3;
        }

        else if (s[i] != 'S' && s[i + 1] != 'O' && s[i + 2] == 'S')
        {
            cnt += 2;
            i += 3;
        }
        else if (s[i] != 'S' && s[i + 1] != 'O' && s[i + 2] != 'S')
        {
            cnt += 3;
            i += 3;
        }
    }
    return cnt;
}

int main()
{

    string s = "SOSSOT";

    int result = marsExploration(s);
    cout << result << "\n";

    return 0;
}
