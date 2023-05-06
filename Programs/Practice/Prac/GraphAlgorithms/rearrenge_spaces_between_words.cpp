#include <bits/stdc++.h>
using namespace std;

string reorderSpaces(string text)
{
    int cnt = 0;
    int i = 0;
    vector<string> v;
    int n = text.size();
    while (i < n)
    {
        string str = "";
        while (i < n && text[i] == ' ')
        {
            cnt++;
            i++;
        }
        while (i < n && text[i] != ' ')
        {
            str += text[i];
            i++;
        }
        if (str.size() > 0)
            v.push_back(str);
    }
    string res = "";
    int x = v.size();
    if (x == 1)
    {
        res += v[0];
        while (cnt--)
            res += ' ';
        return res;
    }
    int y = cnt / (x - 1);
    int p = cnt % (x - 1);
    for (int i = 0; i < v.size() - 1; i++)
    {
        res += v[i];
        for (int j = 0; j < y; j++)
            res += ' ';
    }
    res += v[v.size() - 1];
    while (p--)
        res += ' ';
    return res;
}

int main()
{
    string text = "  this   is  a sentence ";
    cout << reorderSpaces(text);
    return 0;
}