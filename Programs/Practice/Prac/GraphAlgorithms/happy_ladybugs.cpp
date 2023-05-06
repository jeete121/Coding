#include <bits/stdc++.h>
using namespace std;

string happyLadybugs(string b)
{
    int f[26] = {0}, cnt = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] >= 'A' && b[i] <= 'Z')
            f[b[i] - 'A']++;
        else
            cnt++;
    }
    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        if (f[i] == 1)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        return "NO";
    else
    {
        if (cnt > 0)
            return "YES";
        else
        {
            for (int i = 0; i < b.size() - 2; i++)
            {
                for (int j = i + 2; j < b.size(); j++)
                {
                    if (b[j - 1] != b[i] && b[j] == b[i])
                        return "NO";
                }
            }
            return "YES";
        }
    }
}

int main()
{

    int n = 7;
    string b = "RBY_YBR";
    string result = happyLadybugs(b);

    cout << result << "\n";

    return 0;
}
