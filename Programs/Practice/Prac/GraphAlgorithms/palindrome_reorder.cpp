#include <bits/stdc++.h>
using namespace std;

void palindromeReorder(string s)
{

    int f[26] = {0};
    for (int i = 0; i < s.size(); i++)
        f[s[i] - 'A']++;
    string res;
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (f[i] & 1)
            cnt++;
    }
    if (cnt > 1)
        cout << "NO SOLUTION\n";
    else
    {

        res.resize(s.size());
        int m = 0;
        int flag = 0;
        int l = 0, k = s.size() - 1;
        for (int i = 0; i < 26; i++)
        {
            if (f[i] % 2 == 0)
            {
                int x = f[i] / 2;
                int x1 = f[i] / 2;
                while (x--)
                    res[l++] = i + 'A';
                while (x1--)
                    res[k--] = i + 'A';
            }
            else
            {
                flag = 1;
                m = i;
            }
        }
        if (flag == 0)
            cout << res << "\n";
        else
        {
            for (int j = l;; j++)
            {
                res[j] = m + 'A';
                f[m]--;
                if (f[m] == 0)
                    break;
            }
            cout << res << "\n";
        }
    }
}
int main()
{
    string s = "AAAACACBA";

    palindromeReorder(s);

    return 0;
}