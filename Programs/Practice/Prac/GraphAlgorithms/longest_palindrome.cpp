#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s)
{
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
        mp[s[i]]++;
    int f = 0;
    int ans = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second & 1)
        {
            ans += it->second - 1;
            f = 1;
        }
        else
            ans += it->second;
    }
    if (f == 1)
        ans += 1;
    return ans;
}

int main()
{

    string s = "abccccdd";

    cout << longestPalindrome(s);

    return 0;
}