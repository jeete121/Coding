#include <bits/stdc++.h>
using namespace std;

int bobAndString(string s, string t)
{
    int f[26] = {0};
    int f1[26] = {0};
    for (int i = 0; i < s.size(); i++)
        f[s[i] - 'a']++;
    for (int i = 0; i < t.size(); i++)
        f1[t[i] - 'a']++;
    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans += abs(f[i] - f1[i]);
    return ans;
}
int main()
{

    string s = "talentpad", t = "talepdapd";

    cout << bobAndString(s, t) << "\n";

    return 0;
}