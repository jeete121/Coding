#include <bits/stdc++.h>
using namespace std;

int coverPoints(vector<pair<int, int>> v)
{

    int ans = 0;
    for (int i = 1; i < v.size(); i++)
    {
        ans += max(abs(v[i].first - v[i - 1].first), abs(v[i].second - v[i - 1].second));
    }
    return ans;
}

int main()
{
    vector<pair<int, int>> v = {{0, 0}, {1, 1}, {1, 2}};

    cout << coverPoints(v);

    return 0;
}