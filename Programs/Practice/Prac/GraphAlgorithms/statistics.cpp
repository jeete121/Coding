#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
    {

        return a.first > b.first;
    }
    return a.second < b.second;
}

void statistics(int n, vector<pair<string, string>> &data)
{
    map<string, int> mp;
    unordered_set<string> st;
    for (int i = 0; i < n; i++)
    {
        string name = data[i].first, sport = data[i].second;

        if (st.find(name) == st.end())
            mp[sport]++;
        st.insert(name);
    }
    vector<pair<string, int>> v;
    for (auto it = mp.begin(); it != mp.end(); it++)
        v.push_back({it->first, it->second});
    sort(v.begin(), v.end(), cmp);
    int p = v.size();
    cout << v[p - 1].first << "\n";
    cout << mp["football"] << "\n";
}
int main()
{

    int n = 7;

    vector<pair<string, string>> data = {{"abir", "cricket"},
                                         {"aayush", "cricket"},
                                         {"newton", "kabaddi"},
                                         {"abhinash", "badminton"},
                                         {"sanjay", "tennis"},
                                         {"abhinash", "badminton"},
                                         {"govind", "football"}};

    statistics(n, data);

    return 0;
}