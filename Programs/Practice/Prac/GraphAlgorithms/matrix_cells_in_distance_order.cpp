#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
{
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int dis = abs(i - r0) + abs(j - c0);
            mp[dis].push_back({i, j});
        }
    }
    vector<vector<int>> res;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        int j = 0;
        while (j < it->second.size())
        {
            vector<int> v;
            v.push_back(it->second[j].first);
            v.push_back(it->second[j].second);
            res.push_back(v);
            j++;
        }
    }
    return res;
}
int main()
{
    int R = 1, C = 2, r0 = 0, c0 = 0;

    vector<vector<int>> res = allCellsDistOrder(R, C, r0, c0);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (j != res[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}