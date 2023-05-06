#include <bits/stdc++.h>
using namespace std;

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
{
    int x = 0, y = 0, d = 0, res = 0;
    unordered_set<string> set;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (auto &obstacle : obstacles)
    {
        set.insert(to_string(obstacle[0]) + "_" + to_string(obstacle[1]));
    }
    for (int command : commands)
    {
        if (command == -1)
        {
            d = (d + 1) % 4;
        }
        else if (command == -2)
        {
            d = (d + 3) % 4;
        }
        else
        {
            for (int i = 0; i < command; ++i)
            {
                if (set.find(to_string(x + dir[d][0]) + "_" + to_string(y + dir[d][1])) == set.end())
                {
                    x += dir[d][0];
                    y += dir[d][1];
                }
                else
                {
                    break;
                }
                res = max(res, x * x + y * y);
            }
        }
    }
    return res;
}

int main()
{
    vector<int> commands = {4, -1, 4, -2, 4};
    vector<vector<int>> obstacles = {{2, 4}};

    cout << robotSim(commands, obstacles);

    return 0;
}