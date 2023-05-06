#include <bits/stdc++.h>
using namespace std;

string pangrams(string s)
{
    int n = s.size();
    int f[26] = {0};
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
        f[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (f[i] == 0)
            return "not pangram";
    return "pangram";
}

int main()
{

    string s = "We promptly judged antique ivory buckles for the next prize";

    string result = pangrams(s);
    cout << result << "\n";

    return 0;
}
