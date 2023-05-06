#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
    if (a.second.size() == b.second.size())
        return a.first > b.first;
    return a.second.size() > b.second.size();
}
int main()
{

    vector<pair<int, string>> v;
    string str = "ab cd e j asd ljffg df";

    int n = str.size();
    int j = 0;
    int i = 1;
    while (j < n)
    {
        string s = "";
        while (j < n && str[j] != ' ')
        {
            s += str[j];
            j++;
        }
        j++;
        v.push_back({i, s});
        i++;
    }

    sort(v.begin(), v.end(), cmp);
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i].second.size() > 0)
            cout << " " << v[i].second;
    }

    cout << "\n";
    return 0;
}