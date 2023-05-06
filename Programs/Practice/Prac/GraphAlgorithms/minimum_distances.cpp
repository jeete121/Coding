#include <bits/stdc++.h>
using namespace std;

//comparator used for sorting
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
int main()
{
    int n = 6;
    int arr[n] = {7, 1, 3, 4, 1, 7};

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({arr[i], i});
    sort(v.begin(), v.end(), cmp);
    int i = 1;
    int ans = INT_MAX;

    while (i < n)
    {
        while (i < n && v[i].first == v[i - 1].first)
        {
            ans = min(ans, v[i].second - v[i - 1].second);
            i++;
        }
        i++;
    }
    if (ans == INT_MAX)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
    return 0;
}
