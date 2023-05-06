#include <bits/stdc++.h>
using namespace std;

int costBalloons(int g, int p, int n, vector<pair<int, int>> v)
{
    int res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++)
    {
        int a = v[i].first, b = v[i].second;

        res1 += a * g + b * p;
        res2 += a * p + b * g;
    }
    int res = min(res1, res2);
    return res;
}
int main()
{

    int g = 9, p = 6;

    int n = 10;
    vector<pair<int, int>> v = {{1, 1}, {1, 1}, {0, 1}, {0, 0}, {0, 1}, {0, 0}, {0, 1}, {0, 1}, {1, 1}, {0, 0}};

    cout << costBalloons(g, p, n, v) << "\n";

    return 0;
}