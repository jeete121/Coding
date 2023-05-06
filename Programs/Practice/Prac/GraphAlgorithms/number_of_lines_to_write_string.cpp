#include <bits/stdc++.h>
using namespace std;

vector<int> numberOfLines(vector<int> &widths, string s)
{
    vector<int> res;
    map<char, int> mp;
    for (int i = 0; i < widths.size(); i++)
        mp[i + 'a'] = widths[i];
    int i = 0;
    int n = s.size();
    int num = 0;
    while (i < n)
    {
        int cnt = 0;
        while (cnt < 100 && i < n)
        {
            if (cnt + mp[s[i]] > 100)
                break;
            else
                cnt += mp[s[i]];
            i++;
        }
        num++;
        if (i == n)
        {
            res.push_back(num);
            res.push_back(cnt);
        }
    }
    return res;
}

int main()
{
    vector<int> widths = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                          10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                          10, 10, 10, 10, 10, 10};
    string s = "abcdefghijklmnopqrstuvwxyz";

    vector<int> res = numberOfLines(widths, s);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}