#include <bits/stdc++.h>
using namespace std;

bool isvowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int VCPairs(int n, string s)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (!isvowel(s[i]) && isvowel(s[i + 1]))
            cnt++;
    }
    return cnt;
}
int main()
{

    int n = 6;
    string s = "bazeci";

    cout << VCPairs(n, s) << "\n";

    return 0;
}