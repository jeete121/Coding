#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int low = 0, high = s.size() - 1;
    while (low < high)
    {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}
int removePalindromeSub(string s)
{
    if (s.size() == 0)
        return 0;
    if (isPalindrome(s))
        return 1;
    return 2;
}

int main()
{
    string s = "abb";

    cout << removePalindromeSub(s);
    return 0;
}