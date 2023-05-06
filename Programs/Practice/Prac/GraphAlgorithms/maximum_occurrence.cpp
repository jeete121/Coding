#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, char> a, pair<int, char> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

void maximumOccurrence(string str)
{
    int n = str.size();
    int i = 0;
    map<char, int> mp;
    while (i < n)
    {
        mp[str[i]]++;
        i++;
    }
    vector<pair<int, char>> v;
    for (auto it = mp.begin(); it != mp.end(); it++)
        v.push_back({it->second, it->first});
    sort(v.begin(), v.end(), cmp);
    cout << v[v.size() - 1].second
         << " " << v[v.size() - 1].first << "\n";
}
int main()
{
    string str = "Pulkit is a dog!!!!!!!!!!!!";

    maximumOccurrence(str);

    return 0;
}