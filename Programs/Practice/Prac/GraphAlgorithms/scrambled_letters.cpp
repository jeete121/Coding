#include <bits/stdc++.h>
using namespace std;

string scrambledLetters(string s, string t)
{
    int n = s.size();
    int m = t.size();
    if (n != m)
        return "false";
    else
    {
        if (s == t)
            return "true";
        else
        {

            string ans = "";
            for (int i = 0; i < n; i++)
                if (s[i] != t[i])
                    ans += s[i];
            return ans;
        }
    }
}
int main()
{
    string s = "caTS", t = "cats";

    cout << scrambledLetters(s, t);

    return 0;
}