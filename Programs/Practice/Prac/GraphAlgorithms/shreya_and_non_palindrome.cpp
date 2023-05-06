#include <bits/stdc++.h>
using namespace std;

int nonPalindrome(string s)
{

    int len = s.size();
    int flag = 0;
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        return len;
    else
    {
        sort(s.begin(), s.end());
        if (s[0] != s[len - 1])
            return len - 1;
        else
            return 0;
    }
}
int main()
{
    string s = "pqp";

    cout << nonPalindrome(s) << "\n";

    return 0;
}