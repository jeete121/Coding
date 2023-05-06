#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int rooms(int n, int a[], int x[])
{
    int d[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = a[i] + x[i];
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({a[i], d[i]});
    sort(v.begin(), v.end(), cmp);
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++)
    {
        if (q.empty())
            q.push(v[i].second);
        else
        {
            int y = q.top();
            if (y <= v[i].first)
                q.pop();
            q.push(v[i].second);
        }
    }
    return q.size();
}
int main()
{

    int n = 3;

    int a[n] = {1, 2, 3}, x[n] = {3, 3, 3};

    cout << rooms(n, a, x) << "\n";

    return 0;
}