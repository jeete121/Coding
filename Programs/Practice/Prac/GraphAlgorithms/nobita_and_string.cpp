#include <bits/stdc++.h>
using namespace std;

string nobitaAndString(string s)
{
    vector<string> res;
    int i = 0, l = 0;
    string x = "";
    string ans = "";
    while (i < s.size())
    {
        while (i < s.size() && s[i] != ' ')
        {
            x += s[i];
            i++;
        }
        i++;
        res.push_back(x);
        x = "";
    }
    for (int j = res.size() - 1; j >= 0; j--)
    {
        ans += res[j];
        ans += ' ';
    }
    return ans;
}
int main()
{

    string s = "hello world";

    cout << nobitaAndString(s) << "\n";

    return 0;
}