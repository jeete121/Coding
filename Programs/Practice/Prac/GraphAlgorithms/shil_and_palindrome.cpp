#include <bits/stdc++.h>
using namespace std;

void shilAndPalindrome(string s)
{
    int n = s.size();
    int f[26] = {0};
    for (int i = 0; i < n; i++)
        f[s[i] - 'a']++;
    int cnto = 0, cnte = 0;
    sort(s.begin(), s.end());
    for (int i = 0; i < 26; i++)
    {
        if (f[i] > 0 && f[i] & 1)
            cnto++;
        else if (f[i] > 0 && f[i] % 2 == 0)
            cnte++;
    }
    if (cnto == 0 && n & 1)
        cout << -1 << "\n";
    else if (n % 2 == 0 && cnto > 0)
        cout << -1 << "\n";
    else
    {
        char str[n + 1];
        int i = 0;
        int l = 0, j = n - 1;
        while (i < n)
        {
            if ((i < n - 1) && (s[i] == s[i + 1]))
            {
                str[l] = s[i];
                str[j] = s[i + 1];
                i += 2;
                l++;
                j--;
            }
            else
            {
                str[n / 2] = s[i];
                i++;
            }
        }
        string res = "";
        for (int i = 0; i < n; i++)
            res += str[i];
        cout << res << "\n";
    }
}
int main()
{

    string s = "aabcc";

    shilAndPalindrome(s);

    return 0;
}