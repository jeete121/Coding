#include <bits/stdc++.h>
using namespace std;

string antiPalindrome(string s)
{
    sort(s.begin(), s.end());
    int n = s.size();
    if (s[0] == s[n - 1])
        return "-1";
    else
        return s;
}
int main()
{

    string s = "bpc";
    cout << antiPalindrome(s) << "\n";

    return 0;
}