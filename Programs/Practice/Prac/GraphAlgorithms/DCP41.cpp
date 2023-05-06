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
vector<string> findItinerary(vector<vector<string>> &tickets,
                             string start)
{
    for (int i = 0; i < tickets.size(); i++)
    {
        string u = tickets[i][0];
        string v = tickets[i][1];
        ump[u].insert(v);
    }
    fun(start);
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<vector<string>> tickets = {{"SFO", "HKO"},
                                      {"YYZ", "SFO"},
                                      {"YUL", "YYZ"},
                                      {"HKO", "ORD"}};

    string start = "YUL";
    vector<string> res = findItinerary(tickets, start);
    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
        cout << res[i] << ",";
    cout << res[res.size() - 1] << "]";
    return 0;
}