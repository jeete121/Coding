#include <bits/stdc++.h>
using namespace std;

string caseConversion(string s)
{
    int n = s.size();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (i == 0)
                ans += s[i] + 32;
            else
            {
                ans += '_';
                ans += s[i] + 32;
            }
        }
        else
            ans += s[i];
    }
    return ans;
}
int main()
{
    string s = "primeCheck";

    cout << caseConversion(s) << "\n";

    return 0;
}