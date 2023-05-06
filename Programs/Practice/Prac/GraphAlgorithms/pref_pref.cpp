#include <bits/stdc++.h>
using namespace std;

int prefPref(string s, string t)
{

    int n = t.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == s[0])
        {
            j = i;
            break;
        }
    }
    int l = 0;
    int cnt = 0;

    for (int i = j; i < n; i++)
    {
        if (s[l] == t[i])
        {
            cnt++;
            l++;
        }
    }
    return cnt;
}
int main()
{
    string s = "digger", t = "biggerdiagram";

    cout << prefPref(s, t) << "\n";

    return 0;
}