#include <bits/stdc++.h>
using namespace std;

int cityTravel(int s, int x, int n, vector<pair<int, int>> &v)
{
    sort(v.begin(), v.end());
    int cnt = 0;
    int i = 1;
    int j = 0;
    while (s > 0)
    {
        if (v[j].first == i)
        {
            s = s - v[j].second;
            i++;
            j++;
            cnt++;
        }
        else
        {
            s = s - x;
            cnt++;
            i++;
        }
    }
    return cnt;
}
int main()
{
    int s = 21, x = 5, n = 2;

    vector<pair<int, int>> v = {{2, 4}, {4, 8}};

    cout << cityTravel(s, x, n, v) << "\n";

    return 0;
}