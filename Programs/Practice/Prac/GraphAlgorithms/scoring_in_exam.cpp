#include <bits/stdc++.h>
using namespace std;

void scoringInExam(long long n, long long q,
                   long long time[], long long arr[],
                   vector<long long> &queries)
{
    vector<pair<long long, long long>> v;
    for (long long i = 0; i < n; i++)
        v.push_back({arr[i], time[i]});
    sort(v.begin(), v.end());
    long long sum[n];
    sum[n - 1] = v[n - 1].second;
    for (long long i = n - 2; i >= 0; i--)
        sum[i] = sum[i + 1] + v[i].second;
    for (long long i = 0; i < q; i++)
    {
        long long k = queries[i];

        long long res = sum[n - k];
        cout << res << "\n";
    }
}
int main()
{
    long long n = 5, q = 2;

    long long time[n] = {2, 3, 9, 4, 5};
    long long arr[n] = {3, 5, 11, 6, 7};
    vector<long long> queries = {5, 3};

    scoringInExam(n, q, time, arr, queries);

    return 0;
}