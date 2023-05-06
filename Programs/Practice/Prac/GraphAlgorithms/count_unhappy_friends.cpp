#include <bits/stdc++.h>
using namespace std;

int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs)
{
    vector<vector<int>> scores(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            scores[i][preferences[i][j]] = n - 1 - j;
        }
    }

    vector<int> dict(n, -1);
    for (int i = 0; i < pairs.size(); i++)
    {
        dict[pairs[i][0]] = pairs[i][1];
        dict[pairs[i][1]] = pairs[i][0];
    }

    int res = 0;
    for (int x = 0; x < n; ++x)
    {
        int y = dict[x];
        for (int u = 0; u < n; ++u)
        {
            if (scores[x][y] < scores[x][u])
            {
                int v = dict[u];
                if (scores[u][v] < scores[u][x])
                {
                    res++;
                    break;
                }
            }
        }
    }
    return res;
}

int main()
{
    int n = 4;
    vector<vector<int>> preferences = {{1, 2, 3},
                                       {3, 2, 0},
                                       {3, 1, 0},
                                       {1, 2, 0}};

    vector<vector<int>> pairs = {{0, 1}, {2, 3}};

    cout << unhappyFriends(n, preferences, pairs);

    return 0;
}