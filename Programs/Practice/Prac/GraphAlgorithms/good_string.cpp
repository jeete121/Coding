#include <bits/stdc++.h>
using namespace std;

int goodString(string s)
{
    int n = s.size();
    int f[26] = {0};
    for (int i = 0; i < n; i++)
        f[s[i] - 'a']++;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (f[i] > 1)
            ans += f[i] - 1;
    }
    return ans;
}
int main()
{
    string s = "aabc";

    cout << goodString(s) << "\n";

    return 0;
}