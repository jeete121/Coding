#include <bits/stdc++.h>
using namespace std;

bool repeatedSubstringPattern(string t)
{
    int n = t.size();
    if (n < 2)
        return false;
    vector<int> lps(n);
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (t[i] == t[j])
        {
            j++;
            lps[i] = j;
        }
        else if (j)
        {
            j = lps[j - 1];
            i--;
        }
    }
    return lps[n - 1] != 0 && n % (n - lps[n - 1]) == 0;
}

int main()
{
    string s = "abab";

    if (repeatedSubstringPattern(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}