#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, string> a,
         pair<long long, string> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

void theBestPlayer(long long n, long long k,
                   vector<pair<long long, string>> &v)
{
    sort(v.begin(), v.end(), cmp);
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cout << v[i].second << "\n";
        cnt++;
        if (cnt == k)
            break;
    }
}
int main()
{
    long long n = 3, k = 2;

    vector<pair<long long, string>> v = {{3, "surbhi"},
                                         {3, "surpanakha"},
                                         {5, "shreya"}};

    theBestPlayer(n, k, v);

    return 0;
}