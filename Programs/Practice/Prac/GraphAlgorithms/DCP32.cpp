#include <bits/stdc++.h>
using namespace std;

bool DFS_Cycle( vector<vector<double>> &currencies,
               int currency_id, double weight,
               vector<bool> &visited, vector<bool> &in_process)
{
    if (visited[currency_id])
        return false;
    if (in_process[currency_id] && weight > 1.0)
        return true;
    in_process[currency_id] = true;
    for (int i = 0; i < currencies.size(), i != currency_id; i++)
    {
        if (DFS_Cycle(currencies, i, weight * currencies[currency_id][i],
                      visited, in_process))

        {
            return true;
        }
    }
    in_process[currency_id] = false;
    visited[currency_id] = true;
    return false;
}

bool hasArbitrage(vector<vector<double>> &currencies)
{
    int n = currencies.size();

    vector<bool> visited(n, false);
    vector<bool> in_process(n, false);
    return DFS_Cycle(currencies, 0, 1.0, visited, in_process);
}

int main()
{
    vector<vector<double>> currencies = {{1.0, 2.0}, {0.6, 1.0}};
    if (hasArbitrage(currencies))
        cout << "true";
    else

        cout << "false";

    return 0;
}
