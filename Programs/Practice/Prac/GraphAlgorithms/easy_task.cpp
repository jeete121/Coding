#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void connectedPairs(int n, int a[], int b[])
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({a[i], i});
    sort(v.begin(), v.end());
    int k;
    for (int i = 0; i < n; i++)
    {
        k = i;
        vector<pair<int, int>> p;
        while (i < n - 1 && v[i].first == v[i + 1].first)
        {

            p.push_back({v[i].first, v[i].second});
            i++;
        }
        p.push_back({v[i].first, v[i].second});
        int max1 = INT_MIN;
        for (int j = 0; j < p.size(); j++)
        {
            max1 = max(max1, b[p[j].second]);
        }
        for (int j = k; j <= i; j++)
            v[j].first = max1;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << v[i].first << " ";
}
int main()
{
    int n = 5;

    int a[n] = {1, 2, 3, 2, 1};
    int b[n] = {6, 7, 8, 7, 6};

    connectedPairs(n, a, b);

    return 0;
}