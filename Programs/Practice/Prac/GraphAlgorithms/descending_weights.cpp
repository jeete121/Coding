#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long long> a,
         pair<long long, long long> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

void descendingWeights(long long n,
                       long long k, long long a[])
{
    vector<pair<long long, long long>> v;
    for (long long i = 0; i < n; i++)
    {

        v.push_back({a[i], a[i] % k});
    }
    sort(v.begin(), v.end(), cmp);
    for (long long i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " ";
    }
    cout << "\n";
}
int main()
{
    long long n = 5, k = 2;

    long long a[n] = {1, 2, 3, 4, 5};

    descendingWeights(n, k, a);

    return 0;
}