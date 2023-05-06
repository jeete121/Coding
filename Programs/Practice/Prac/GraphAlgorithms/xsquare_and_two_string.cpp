#include <bits/stdc++.h>
using namespace std;

void xsquareAndTwoStrings(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[s1[i]]++;
    int flag = 0;
    for (int i = 0; i < m; i++)
    {
        if (mp[s2[i]])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "No\n";
    else
        cout << "Yes\n";
}
int main()
{

    string s1 = "phackerekarthj";
    string s2 = "jhakckerearthp";

    xsquareAndTwoStrings(s1, s2);

    return 0;
}