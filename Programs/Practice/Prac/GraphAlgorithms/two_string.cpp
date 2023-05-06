#include <bits/stdc++.h>
using namespace std;

string twoStrings(string s1, string s2)
{
    int f1[26] = {0}, f2[26] = {0};
    for (int i = 0; i < s1.size(); i++)
    {
        f1[s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        f2[s2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (f1[i] > 0 && f2[i] > 0)
        {
            return "YES";
        }
    }
    return "NO";
}

int main()
{

    string s1 = "hello";
    string s2 = "world";

    string result = twoStrings(s1, s2);
    cout << result << "\n";

    return 0;
}
