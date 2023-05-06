#include <bits/stdc++.h>
using namespace std;

bool palindromicString(string s)
{
    int n = s.size();
    int flag = 0;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            flag = 1;
            break;
        }
        i++;
        j--;
    }
    if (flag)
        return false;
    else
        return true;
}
int main()
{
    string s = "aba";

    if (palindromicString(s))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}