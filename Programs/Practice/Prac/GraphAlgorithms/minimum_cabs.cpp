#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<double, double> a, pair<double, double> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int minimumCabs(int n, vector<vector<int>> &arr)
{
    vector<pair<double, double>> v;
    for (int i = 0; i < n; i++)
    {
        double s1 = arr[i][0], s2 = arr[i][1];
        double e1 = arr[i][2], e2 = arr[i][3];

        double x1 = s2 / 60, x2 = e2 / 60;
        v.push_back({x1 + s1, e1 + x2});
    }
    sort(v.begin(), v.end(), cmp);
    priority_queue<double, vector<double>, greater<double>> q;
    for (int i = 0; i < n; i++)
    {
        if (q.empty())
            q.push(v[i].second);
        else
        {
            double y = q.top();
            if (y < v[i].first)
                q.pop();
            q.push(v[i].second);
        }
    }
    return q.size();
}
int main()
{

    int n = 6;

    vector<vector<int>> arr = {{1, 0, 2, 0},
                               {16, 0, 21, 30},
                               {9, 30, 13, 0},
                               {21, 30, 22, 30},
                               {21, 30, 22, 30},
                               {12, 0, 12, 30}};

    cout << minimumCabs(n, arr) << "\n";

    return 0;
}