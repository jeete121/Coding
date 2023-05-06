#include <bits/stdc++.h>
using namespace std;

int stringConstruction(string s)
{
    int f[26] = {0}, cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (f[s[i] - 'a'] == 0)
        {
            f[s[i] - 'a']++;
            cnt++;
        }
        else
            f[s[i] - 'a']++;
    }
    return cnt;
}

int main()
{

    int q = 1;

    string s = "abab";

    int result = stringConstruction(s);

    cout << result << "\n";

    return 0;
}
