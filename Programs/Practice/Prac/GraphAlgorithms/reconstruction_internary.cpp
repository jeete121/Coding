#include <bits/stdc++.h>
using namespace std;

vector<string> res;
map<string, multiset<string>> ump;

void fun(string x)
{
    while (ump[x].size() > 0)
    {
        auto it = ump[x].begin();
        string y = *it;
        ump[x].erase(ump[x].begin());
        fun(y);
    }
    res.push_back(x);
}
vector<string> findItinerary(vector<vector<string>> &tickets)
{
    for (int i = 0; i < tickets.size(); i++)
    {
        string u = tickets[i][0];
        string v = tickets[i][1];
        ump[u].insert(v);
    }
    fun("JFK");
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<string> res = findItinerary(tickets);
    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
        cout << res[i] << ",";
    cout << res[res.size() - 1] << "]";
    return 0;
}