#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

string pizzaConfusion(vector<pair<int, string>> &v, int n)
{
    sort(v.begin(), v.end(), cmp);
    return v[n - 1].second;
}
int main()
{
    int n = 3;
    vector<pair<int, string>> v = {{108, "Pizzeria"},
                                   {145, "Dominos"},
                                   {49, "Pizzapizza"}};

    cout << pizzaConfusion(v, n) << "\n";

    return 0;
}