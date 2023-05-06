#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int flag = 0;
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        return false;
    else
        return true;
}
int main()
{

    string s = "aba";

    if (isPalindrome(s))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}