#include <bits/stdc++.h>
using namespace std;

string hackerrankInString(string s)
{
    int n = s.size();
    int i = 0;
    vector<char> res;
    while (i < n && s[i] != 'h')
        i++;
    if (i < n)
        res.push_back(s[i]);
    i = i + 1;
    while (i < n && s[i] != 'a')
        i++;
    if (i < n)
        res.push_back(s[i]);
    i++;
    while (i < n && s[i] != 'c')
        i++;
    if (i < n)
        res.push_back(s[i]);
    i++;
    while (i < n && s[i] != 'k')
        i++;
    if (i < n)
        res.push_back(s[i]);
    i++;
    while (i < n && s[i] != 'e')
        i++;
    if (i < n)
        res.push_back(s[i]);
    i++;
    while (i < n && s[i] != 'r')
        i++;
    if (i < n)
        res.push_back(s[i]);
    i++;
    while (i < n && s[i] != 'r')
        i++;
    if (i < n)
        res.push_back(s[i]);
    i++;
    while (i < n && s[i] != 'a')
        i++;
    if (i < n)
        res.push_back(s[i]);
    i++;
    while (i < n && s[i] != 'n')
        i++;
    if (i < n)
        res.push_back(s[i]);
    i++;
    while (i < n && s[i] != 'k')
        i++;
    if (i < n)
        res.push_back(s[i]);
    i++;
    if (res.size() == 10)
        return "YES";
    return "NO";
}

int main()
{

    string s = "hhaacckkekraraannk";

    string result = hackerrankInString(s);
    cout << result << "\n";

    return 0;
}
