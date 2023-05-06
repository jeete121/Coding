#include <bits/stdc++.h>
using namespace std;

void labFileWork(int n, vector<pair<int, int>> &v)
{

    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        int x = v[i].first, y = v[i].second;
        vec.push_back({x + y, i + 1});
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
    {
        cout << vec[i].second << " ";
    }
}
int main()
{

    int n = 5;

    vector<pair<int, int>> v = {{8, 1},
                                {4, 2},
                                {5, 6},
                                {3, 1},
                                {4, 3}};

    labFileWork(n, v);

    return 0;
}