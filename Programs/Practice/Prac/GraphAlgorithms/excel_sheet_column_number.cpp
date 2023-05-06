#include <bits/stdc++.h>
using namespace std;

int titleToNumber(string s)
{
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res * 26;
        res += s[i] - 'A' + 1;
    }
    return res;
}

int main()
{
    string s = "ZY";
    cout << titleToNumber(s);

    return 0;
}