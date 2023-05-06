#include <bits/stdc++.h>
using namespace std;

int stringClash(string s, string t)
{

    int n = s.size();
    int m = t.size();
    int f[26] = {0};
    for (int i = 0; i < n; i++)
        f[s[i] - 'a']++;
    for (int i = 0; i < m; i++)
        f[t[i] - 'a']++;
    int cnt = 0, flag = 0;
    for (int i = 0; i < 26; i++)
    {
        if (f[i] % 2 == 0)
            cnt += f[i];
        else
        {
            if (f[i] > 1)
                cnt += f[i] - 1;
            flag = 1;
        }
    }
    if (flag == 1)
        cnt += 1;
    return cnt;
}
int main()
{
    string s = "aab", t = "cba";

    cout << stringClash(s, t) << "\n";

    return 0;
}