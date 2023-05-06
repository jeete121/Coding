#include <bits/stdc++.h>
using namespace std;

string swappingCharacters(int n, string s)
{
    int j = 0;
    string res = "", temp = "";
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            res += s[i];
        else
            temp += s[i];
    }
    for (int i = temp.size() - 1; i >= 0; i--)
        res += temp[i];
    return res;
}
int main()
{

    int n = 6;

    string s = "abcdef";

    cout << swappingCharacters(n, s) << "\n";

    return 0;
}