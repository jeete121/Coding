#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, 
pair<long long, long long>> a, pair<long long, 
pair<long long, long long>> b)
{

    if (a.first == b.first)
        return a.second.first < b.second.first;
    return a.first < b.first;
}
long long count(long long n)
{
    long long res = 0;
    while (n)
    {
        n = n & (n - 1);
        res++;
    }
    return res;
}
int main()
{

    long long n = 4;

    long long a[n] = {3, 4, 7, 10};

    vector<pair<long long, pair<long long, long long>>> v;
    for (long long i = 0; i < n; i++)
    {
        long long cnt = count(a[i]);
        v.push_back(make_pair(cnt, make_pair(i, a[i])));
    }
    sort(v.begin(), v.end(), cmp);
    for (long long i = 0; i < n; i++)
        cout << v[i].second.second << " ";
    cout << "\n";

    return 0;
}