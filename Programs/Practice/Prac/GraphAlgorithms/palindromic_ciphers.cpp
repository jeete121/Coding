#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string s)
{
    long long n = s.size();
    for (long long i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}
int main()
{

    string s = "zazaz";

    if (ispalindrome(s))
        cout << "Palindrome\n";
    else
    {
        long long ans = 1, n = s.size();
        for (long long i = 0; i < n; i++)
            ans = ans * (s[i] - 'a' + 1);
        cout << ans << "\n";
    }

    return 0;
}