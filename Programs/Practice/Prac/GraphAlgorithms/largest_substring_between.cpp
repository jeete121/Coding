#include <bits/stdc++.h>
using namespace std;

int maxLengthBetweenEqualCharacters(string s)
{
    vector<pair<char, int>> v;
    for (int i = 0; i < s.size(); i++)
        v.push_back({s[i], i});
    sort(v.begin(), v.end());
    int i = 0;
    int ans = -1;
    int n = s.size();
    while (i < n)
    {
        int j = i;
        while (i + 1 < n && v[i].first == v[i + 1].first)
            i++;
        if (i == n)
            break;
        ans = max(ans, v[i].second - v[j].second - 1);
        i++;
    }
    return ans;
}

int main()
{
    string str = "abca";
    cout << maxLengthBetweenEqualCharacters(str);
    return 0;
}