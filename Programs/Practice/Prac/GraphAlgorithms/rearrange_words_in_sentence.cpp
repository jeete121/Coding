#include <bits/stdc++.h>
using namespace std;


//comparator used for sorting
bool static cmp(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
    if (a.second.first == b.second.first)
        return a.second.second < b.second.second;
    return a.second.first < b.second.first;
}
string arrangeWords(string s)
{
    int n = s.size();
    int i = 0;
    vector<pair<string, pair<int, int>>> v;
    while (i < n)
    {
        string str = "";
        while (s[i] == ' ')
            i++;
        int j = i;
        while (i < n && s[i] != ' ')
        {
            str += s[i];
            i++;
        }
        i++;
        v.push_back(make_pair(str, make_pair(str.size(), j)));
    }
    string res = "";
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (i == 0)
        {
            string x = v[i].first;
            if (x[0] >= 'a' && x[0] <= 'z')
                x[0] = x[0] - 32;
            res += x;
            res += " ";
        }
        else
        {
            string x = v[i].first;
            if (x[0] >= 'A' && x[0] <= 'Z')
                x[0] = x[0] + 32;
            res += x;
            res += " ";
        }
    }
    string x = v[v.size() - 1].first;
    if (x[0] >= 'A' && x[0] <= 'Z')
        x[0] = x[0] + 32;
    res += x;
    return res;
}

int main()
{
    string text = "Keep calm and code on";
    cout << arrangeWords(text);
    return 0;
}