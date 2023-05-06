#include <bits/stdc++.h>
using namespace std;

bool searhMe(string s)
{
    int n = s.size();
    int i = 0;
    vector<pair<string, int>> v;
    while (i < n)
    {
        string str = "";
        int j = i;
        while (i < n && s[i] != ' ')
        {
            str += s[i];
            i++;
        }
        i++;
        v.push_back({str, j});
    }
    int flag = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i].first == "to" && v[i + 1].first == "the")
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return false;
    else
        return true;
}
int main()
{
    string s = "to order the monk";

    if (searhMe(s))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}