#include <bits/stdc++.h>
using namespace std;

vector<string> subdomainVisits(vector<string> &cpdomains)
{
    unordered_map<string, int> mp;
    for (auto i : cpdomains)
    {
        int x = i.find(" ");
        int n = stoi(i.substr(0, x));
        string s = i.substr(x + 1);
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == '.')
                mp[s.substr(i + 1)] += n;
        mp[s] += n;
    }
    vector<string> res;
    for (auto it = mp.begin(); it != mp.end(); it++)
        res.push_back(to_string(it->second) + " " + it->first);
    return res;
}
int main()
{
    vector<string> cpdomains = {"900 google.mail.com",
                                "50 yahoo.com",
                                "1 intel.mail.com",
                                "5 wiki.org"};

    vector<string> res = subdomainVisits(cpdomains);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}