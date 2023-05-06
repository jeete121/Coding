#include <bits/stdc++.h>
using namespace std;

vector<int> avoidFlood(vector<int> &rains)
{
    set<int> sun;
    unordered_map<int, int> last_rain;
    vector<int> ans(rains.size(), -1);
    for (int i = 0; i < rains.size(); ++i)
    {
        if (rains[i] == 0)
        {
            sun.insert(i);
            ans[i] = 1;
        }
        else
        {
            if (last_rain.count(rains[i]) > 0)
            {
                // the lake is full, we should
                // find the first sun day after the last rain day
                auto it = sun.upper_bound(last_rain[rains[i]]);
                // can not find the way to dry the lake
                if (it == end(sun))
                {
                    return {};
                }
                ans[*it] = rains[i];
                sun.erase(it);
            }
            // mark the last rain day
            last_rain[rains[i]] = i;
        }
    }
    return ans;
}

int main()
{
    vector<int> rains = {1, 2, 0, 0, 2, 1};

    vector<int> res = avoidFlood(rains);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}