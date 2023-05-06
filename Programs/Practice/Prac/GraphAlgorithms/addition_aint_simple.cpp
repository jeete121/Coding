#include <bits/stdc++.h>
using namespace std;

string additionAintSimple(string s)
{

    map<char, int> mp;
    for (int j = 0; j < 26; j++)
        mp['a' + j] = j + 1;

    map<int, char> mp1;
    for (int i = 0; i < 26; i++)
        mp1[i + 1] = 'a' + i;
    string y = s;

    reverse(s.begin(), s.end());
    string str = "";

    for (int j = 0; j < s.size(); j++)
    {

        int x = mp[s[j]] + mp[y[j]];
        x = x % 26;
        if (x == 0)
            str += 'z';
        else
            str += mp1[x];
    }
    return str;
}
int main()
{

    string s = "hello";

    cout << additionAintSimple(s) << "\n";

    return 0;
}