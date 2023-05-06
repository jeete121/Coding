#include <bits/stdc++.h>
using namespace std;

void theDetective(string s1, string s2)
{

    int i = 0, j = 0;
    vector<string> v, v1;
    int n = s1.size(), m = s2.size();
    int f[26] = {0}, f1[26] = {0};
    for (int i = 0; i < n; i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
            s1[i] = s1[i] + 32;
        if (s1[i] >= 'a' && s1[i] <= 'z')
            f[s1[i] - 'a']++;
    }
    for (int i = 0; i < m; i++)
    {
        if (s2[i] >= 'A' && s2[i] <= 'Z')
            s2[i] = s2[i] + 32;
        if (s2[i] >= 'a' && s2[i] <= 'z')
            f[s2[i] - 'a']--;
    }
    sort(f, f + 26);
    sort(f1, f1 + 26);
    if (f[0] == 0 && f[25] == 0 && f1[0] == 0 && f1[25] == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    string s1 = "jogod #! siara.", s2 = "raja is good!";

    theDetective(s1, s2);

    return 0;
}