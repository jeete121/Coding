#include <bits/stdc++.h>
using namespace std;

void palindromeString(string s)
{
    int n = s.size();
    int flag = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";
}
int main()
{
    string s = "madam";

    palindromeString(s);

    return 0;
}